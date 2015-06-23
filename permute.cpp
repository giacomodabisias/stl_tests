#include <iostream>
#include <vector>
#include <algorithm>

int order(std::vector<int> p) {

	if(p.size() == 0 || p.size() == 1)
		return 0;

	std::vector<int> v;
	v.resize(p.size());
	for(int i = 0; i < p.size(); ++i)
		v[i] = i;

	int n = 0;
	bool found_distinct = false;

	while(true){
		for(int j = 0 ; j < p.size(); ++j)
			std::swap(v[j],v[p[j]]);

		n++;
		for(int i = 0; i < v.size(); ++i){ 
			if(v[i] != i){
				found_distinct = true;
				break;
			}
		}
		if(!found_distinct)
			break;
		found_distinct = false;
	}
		
	for(auto p : v)
		std::cout << p << " " ;
	std::cout << std::endl;
	return n;


}


int main () {
std::vector<int> p = {3,2,4,1,0};

std::cout << order(p) << std::endl;


}