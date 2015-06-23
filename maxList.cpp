#include <iostream>
#include <vector>
#include <cmath>
#include <random>


struct gen_rand { 
    int factor;
public:
    gen_rand(int factor = 1000000): factor(factor) {srand(time(NULL));}
    int operator()() { 
        return rand() % factor;
    }
};

int main(int argc, char * argv[]){
	
	int size = argc > 1 ? atoi(argv[1]) : 1000;
		
	// filling the vector with random numbers
	std::vector<int> v;
	v.resize(size);

	std::cout << "generating random vector" << std::endl;

	std::generate(v.begin(), v.end(), gen_rand());

	std::cout << "generated random vector" << std::endl;
	std::cout << "using iteration" << std::endl;

	clock_t begin_time = clock();

	int max = 0;
	for(auto p : v)
		max = std::max(max, p);


	float time_ = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
	std::cout << "time: " << time_ << std::endl;

	std::cout << "max " << max << std::endl;

	std::cout << "using stl" << std::endl;

	begin_time = clock();
	max = *max_element(v.begin(), v.end());
	time_ = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
	std::cout << "time: " << time_ << std::endl;

	std::cout << "max " << max << std::endl;
}