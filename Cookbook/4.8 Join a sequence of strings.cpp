#include <iostream>
#include <string>
#include <vector>


using namespace std;

void join(const vector<string>& v, char c, string& s) { //vector string output, delimiter, string object
	s.clear(); 
	//use const_iterator as v is declared as a ref to const object
	for (vector<string>::const_iterator p = v.begin(); p != v.end(); p++) {
		s += *p; 
		if (p != v.end() - 1) {
			s += c;
		}
	}
}


int main(int argc, char *argv[]) {
	vector<string> v; 
	vector<string> v2; 
	string s;
	
	v.push_back(string("fee"));
	v.push_back(string("foo"));
	v.push_back(string("fi"));
	v.push_back(string("fum"));
	
	join(v, ' ', s);
	
	cout << s << '\n'; 
	
}