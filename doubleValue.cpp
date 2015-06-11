#include <iostream>
#include <vector>
#include <unordered_set>
#include <boost/dynamic_bitset.hpp>
#include <random>
#include <algorithm>
#include <time.h>
#include <set>


struct gen_rand { 
    int factor;
public:
    gen_rand(int factor = 1000000): factor(factor) {srand(time(NULL));}
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
		if(h.find(v[i]) == h.end()){
			h.insert(v[i]);
			++i;
		}
		else{
			std::swap(v[i], v[r]);
			r--;
		}
		
	}

	v.resize(r);
	return h.size();
}

void bitset(std::vector<int> &v, int max){
	
	boost::dynamic_bitset<> bits(max+2);
	std::cout << "bitset size " << max << std::endl;
	int r = v.size() - 1;
	int i = 0;
	while(i < r){
		if(!bits[v[i]]){
			bits[v[i]].flip();
			++i;
		}
		else{
			std::swap(v[i], v[r]);
			r--; 
		}
	}
	v.resize(r);

}

template <typename T>
void set(std::vector<T> &v){

	std::set<T> s;
	for(auto &p : v)
		s.insert(p);	
	
	v.clear();
	std::copy(s.begin(), s.end(), std::back_inserter(v));
}


int main(int argc, char * argv[]){

	int size = argc > 1 ? atoi(argv[1]) : 1000;
	
	// filling the vector with random numbers
	std::vector<int> v;
	v.resize(size);
	std::generate_n(v.begin(), size, gen_rand());
	std::vector<int> v2 = v;
	std::vector<int> v3 = v;

	// getting the size of the bitset
	int max = *std::max_element(v.begin(), v.end());

	std::cout << "size: " << size << " max: " << max << std::endl;

	std::cout << "using unordered_set" << std::endl;
	
	clock_t begin_time = clock();

	unordered(v);

	float time_ = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
	std::cout << "time: " << time_ << std::endl;
	std::cout << "removed " << size - v.size() << " elements!" << std::endl;
	
	// works only with int
	std::cout << "using bitset" << std::endl;
	

	bitset(v2, max);

	float time_2 = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
	std::cout << "time: " << time_2 << std::endl;
	std::cout << "removed " << size - v2.size() << " elements!" << std::endl;

	std::cout << "using set" << std::endl;
	
	begin_time = clock();

	set(v3);

	
	std::cout << std::fixed;
	float time_3 = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
	std::cout << "time: " << time_2 << std::endl;
	std::cout << "removed " << size - v3.size() << " elements!" << std::endl;

	

}