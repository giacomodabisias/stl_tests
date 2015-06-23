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

	for(int i = v.size(); i > 0; --i){

		for(int j = 0; j < i - 1; ++j){
			if(v[j] > v[j + 1])
				std::swap(v[j], v[j+1]);
		}
	}

	for(auto p : v)
		std::cout << p << " ";
	std::cout << std::endl;

}