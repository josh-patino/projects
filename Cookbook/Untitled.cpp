#include <iostream>

using namespace std;

void counter() {
	static int count = 0;
	std::cout << count++; 
}

int main(int argc, char *argv[]) {
	for (int i = 0; i < 5; i++) {
		counter();
	}
}