#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
	string s = "Josh Patino";
	string p = "AGATGCCATATATATACGATATCCTTA"; 

	//search from beginning
	cout << s.find("os")<<endl;
	
	//search from end
	cout << s.rfind("os")<<endl;
	
	//find the first of any of these chars
	cout << s.find_first_of("sti")<<endl;
	
	//find first that is not in this set
	cout << s.find_first_not_of("Patino")<<endl;

	//find the first of any of these chars from end to start
	cout << s.find_last_of("ngk")<<endl;

	//find the first thats not in this set, starting from the end
	cout << s.find_last_not_of("Ptiano")<<endl; 
	
	
}