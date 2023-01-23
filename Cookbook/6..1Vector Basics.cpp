#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	vector<int> intVec;
	vector<string> strVec;
	
	//add elements to the "back" of the vector
	intVec.push_back(3);
	intVec.push_back(9);
	intVec.push_back(6);
	
	string s = "Army";
	strVec.push_back(s);
	s = "Navy";
	strVec.push_back(s);
	s = "Air Force";
	strVec.push_back(s);
	
	//access with operator[], like an array
	for(vector<string>::size_type i = 0; i < intVec.size(); ++i){
		cout << "intVec[" << i << "] = " << intVec[i]<<endl; 
	}
	
	//use iterators
	for(vector<string>::iterator p = strVec.begin(); p != strVec.end(); p++){
		cout << *p << endl; 
	}
}