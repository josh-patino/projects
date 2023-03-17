#include <iostream>
#include <string>


class Entity {
public: 
	float x, y;
	
	Entity(){ 
		// will always run first, if not typed, then it will be defaulted to 
		// Entity() {}
		x = 0.0;
		y=0.0;
	}
	Entity(float xa, float ya){
		x=xa;
		y=ya; 
	}
	
	void Print(){
		std::cout << x << ',' << y << std::endl; 
	}
};

int main() {
	Entity e;
	Entity e1(1.3,2.1);
	e.Print();
	e1.Print();
};