#include <iostream>
#include <vector>
#include <string>
#include <stack>

int main(int argc, char * argv[]){
	
	std::vector<std::string> v = {"(","(","(",")",")","(",")",")"};

	std::stack<std::string> s;

	std::cout << "input" << std::endl;
	for(auto p : v){
		std::cout << p << " ";
	}
	std::cout << std::endl;

	std::string cs = std::string("(");

	for(auto &p : v){
		if(p == cs){
			s.push(p);
		}
		else{
			if(s.size() == 0){
				s.push(p);
				break;
			}
			if(s.top() != cs){
				break;
			}else{
				s.pop();
			}
		}
	}

	if(s.size() == 0)
		std::cout << "the sequence is correct" << std::endl;
	else
		std::cout << "the sequence is incorrect" << std::endl;

}