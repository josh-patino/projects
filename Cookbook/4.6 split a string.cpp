#include <iostream>
#include <vector>
#include <functional>
#include <string>

using namespace std; 

void split(const string& s, char c, vector<string>& v) { //string noneditable, deliminter, vector noneditable
	string::size_type i = 0;  //any size string size_type
	string::size_type j = s.find(c);//finds the first occurance of the | 
	
	
	while (j != string::npos){ // npos is the end of string
		v.push_back(s.substr(i, j - i));  // pushes text before | to vector 
		i = ++j;
		j = s.find(c, j); //finds the next occurannce with a new further range
		if (j == string::npos) {
			v.push_back(s.substr(i, s.length())); // last | push the text after it to EOL
		}
	}
}

int main(int argc, char *argv[]) {
	vector<string> v; 
	
	string s = "Account Name|Address 1|Address 2|City";
	
	split(s, '|', v);
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] <<endl; 
	}
}