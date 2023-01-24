#include <iostream>
#include <typeinfo>

using namespace std;

class Base {
public: 
	virtual ~Base(){} // make this a polynorphic class
};

class Derived : public Base {
public: 
	virtual ~Derived(){}
};

int main(int argc, char *argv[]) {
	
	Derived d; 
	
	//Query the type relationship
	if(dynamic_cast<Base*> (&d)){
		cout << "(Derived) class is a subclass of (Base)" << endl; 
	} else {
		cout<< "(Derived) class is not a subclass of (Base)" << endl;
	}
}