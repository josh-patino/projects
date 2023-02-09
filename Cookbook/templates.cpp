#include <iostream>

using namespace std;


template<typename T>
struct printer {
	void operator()(const T& s) {
		cout << s <<'\n'; 
	} 
};
printer<int> intPrinter; 

template<typename T>
void print(T num, int n) {
	cout << num * n <<endl;
}


int main(int argc, char *argv[]) {
	intPrinter(5);
	print<float>(5.5,5);
}