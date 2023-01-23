#include <iostream>
#include <string>



int main(int argc, char *argv[]) {
	
	//std::reverse
	std::string jp = "joshPatino"; 
	std::reverse(jp.begin(), jp.end()); 
	std::cout << jp <<std::endl;  
	
	//reverse iterator
	std::string mk = "MeridithKoch"; 
	std::string rs; 
	
	rs.assign(mk.rbegin(), mk.rend()); 
	std::cout<< rs; 
	
}