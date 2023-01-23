#include <iostream>
#include <string>
using namespace std;

class Foo {
	public: // constructors with initialized member variables with values
	Foo() : counter_(0), str_(NULL){}
	Foo(int c, string* p) : counter_(c), str_(p) {}
private:
	int counter_;
	string* str_; 
};

int main(int argc, char *argv[]) {
	string s = "bar";
	Foo(2, &s); 
}