#include <iostream>

using namespace std;

class Entity {
private: 
	int x, y;
public:
	// wont modify any member class variables
	//like a read only
	int GetX() const{
		return x; 
	}
	//entity const, wont modity the const e 
	void PrintEntity(const Entity& e) {
		std::cout << e.GetX() << std::endl;
	}
	
};


int main(int argc, char *argv[]) {
	Entity e;
}