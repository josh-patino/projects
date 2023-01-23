#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

template<typename T>
struct printer {
	void operator()(const T& s) {
		cout << s <<'\n'; 
	} 
};

bool inline even(int n) {
	return (n % 2 ==0);
}

printer<string> strPrinter;
printer<int> intPrinter; 

int main(int argc, char *argv[]) {
	list<string> lstOne;
	list<string> lstTwo;
	
	lstOne.push_back("Red");
	lstOne.push_back("Green");
	lstOne.push_back("Blue");
	
	
	lstTwo.push_front("Orange");
	lstTwo.push_front("Yellow");
	lstTwo.push_front("Fuschia");
	
	//for_each(start, end, function to print)
	for_each(lstOne.begin(), lstOne.end(), strPrinter);
	//sort each list
	lstOne.sort(); 
	lstTwo.sort();
	// merge both and print
	lstOne.merge(lstTwo);
	for_each(lstOne.begin(), lstOne.end(), strPrinter); 
	
	list<int> intLst;
	intLst.push_back(0);
	intLst.push_back(1);
	intLst.push_back(2);
	intLst.push_back(3);
	intLst.push_back(4);
	
	intLst.remove_if(bind2nd(greater<int>(), 2));
	
	for_each(intLst.begin( ), intLst.end( ),intPrinter);
	
	intLst.remove_if(even); 
	
}