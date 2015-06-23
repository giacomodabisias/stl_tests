#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

int main (int argc, char * argv[]) {
	
std::string sentence("this is a long string");

std::istringstream iss(sentence);

std::vector<std::string> tokens;

std::copy(std::istream_iterator<std::string>(iss),
     std::istream_iterator<std::string>(),
     std::back_inserter(tokens));

std::reverse(tokens.begin(), tokens.end());

for(auto t : tokens)
	std::cout << t << " ";

std::cout << std::endl<< "second way " << std::endl;

std::istringstream iss2(sentence);

std::vector<std::string> tokens2;

std::string tmp;
while(iss2){
	if(iss2.eof())
		break;
	iss2 >> tmp;
	std::reverse(tmp.begin(), tmp.end());
	tokens2.push_back(tmp);
}

std::reverse(tokens2.begin(), tokens2.end());


for(std::vector<std::string>::iterator itr = tokens2.begin(); itr != tokens2.end(); ++itr)
	std::cout << *itr << " ";
std::cout << std::endl;



}