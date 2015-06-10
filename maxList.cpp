#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char * argv[]){
	
std::vector<int> v = {4,5,1,23,5,76,4,2};

//std::cout << "max " << std::max(v.begin(), v.end()) << std::endl;

int max = 0;
for(auto p : v)
	max = std::max(max, p);

std::cout << "max " << max << std::endl;

}