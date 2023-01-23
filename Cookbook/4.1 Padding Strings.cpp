#include <iostream>
#include <string.h>


int main(int argc, char *argv[]) {
	//end append
	std::string s = "foo"; 
	s.append(20-s.length(), 'X');
	
	std::cout << s << std::endl;
	
	//beginning
	//s.insert(s.begin(), 20 - s.length(), 'X'); 
	std::cout << s << std::endl;

}