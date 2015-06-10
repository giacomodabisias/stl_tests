#include <iostream>
#include <vector>
#include <unordered_set>
#include <boost/dynamic_bitset.hpp>
#include <random>
#include <algorithm>
#include <time.h>


struct gen_rand { 
    int factor;
public:
    gen_rand(int factor = 100): factor(factor) {srand(time(NULL));}
    int operator()() { 
        return rand() % factor;
    }
};

template <typename T>
int unordered(std::vector<T> &v){

	std::unordered_set<T> h;
	int r = v.size() - 1;
	int i = 0;
	while(i < r){
		if(h.find(v[i]) == h.end())
			h.insert(v[i]);
		else{
			std::swap(v[i], v[r]);
			r--;
		}
		++i;
	}
	v.resize(r);
	return h.size();
}

template <typename T>
void bitset(std::vector<T> &v, int max){
	
	boost::dynamic_bitset<> bits(max+2);
	std::cout << "bitset size " << max << std::endl;
	int r = v.size() - 1;
	int i = 0;
	while(i < r){
		if(!bits[v[i]]){
			bits[v[i]].flip();
		}
		else{
			std::swap(v[i], v[r]);
			r--; 
		}
		++i;
	}
	v.resize(r);
}


int main(int argc, char * argv[]){

	int size = argc > 1 ? atoi(argv[1]) : 1000;
	
	// filling the vector with random numbers
	std::vector<int> v;
	v.resize(size);
	std::generate_n(v.begin(), size, gen_rand());
	std::vector<int> v2 = v;

	// getting the size of the bitset
	int max = *std::max_element(v.begin(), v.end());

	std::cout << "size: "  << size << " max: " << max << std::endl;

	std::cout << "using unordered_set" << std::endl;
	
	clock_t begin_time = clock();
	int m = unordered(v);

	std::cout << std::fixed;
	float time_ = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
	std::cout << "time: " << time_ << std::endl;
	std::cout << "removed " << size - v.size() << " elements! using " << (float)m*4/1024/1024 <<"MB of additional memory" << std::endl;
	
	std::cout << "using bitset" << std::endl;
	
	begin_time = clock();
	bitset(v2, max);
	
	std::cout << std::fixed;
	float time_2 = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
	std::cout << "time: " << time_2 << std::endl;
	std::cout << "removed " << size - v2.size() << " elements! using " << (float)m/1024/1024 <<"MB of additional memory" << std::endl;

	if(time_ > time_2)
		std::cout << "bitset is faster by a factor " << time_ / time_2 << std::endl;
	else
		std::cout << "unordered_set is faster by a factor " << time_2 / time_ << std::endl;

}