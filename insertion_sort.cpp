#include <iostream>
#include <vector>
#include <random>
#include <algorithm>


struct gen_rand { 
    int factor;
public:
    gen_rand(int factor = 10): factor(factor) {srand(time(NULL));}
    int operator()() { 
        return rand() % factor;
    }
};

int main (int argc, char ** argv){
	
	int size = argc > 1 ? atoi(argv[1]) : 1000;
	std::vector<int> v;

	std::cout << "generating random vectors" << std::endl;
	v.resize(size);
	std::generate(v.begin(), v.end(), gen_rand());
	std::cout << "generated random vectors" << std::endl;

	for(auto p : v)
		std::cout << p << " ";
	std::cout << std::endl;

	for(int i = 1; i < v.size(); ++i){

		int key = v[i];
		int j = i - 1;

		while(j >= 0 && v[j] > key ){
			std::swap(v[j+1], v[j]);
			j--;
		}
	}

	for(auto p : v)
		std::cout << p << " ";
	std::cout << std::endl;

}