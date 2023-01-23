#include <iostream>
#include <vector>
using namespace std;

static const int NUM_OBJECTS = 10; 

class MyClass {};


int main()
{
	vector<MyClass*> vec; 
	
	MyClass* p = NULL; 
	
	//load up the vector with MyClass objects
	for(int i = 0;i < NUM_OBJECTS; i++ ){
		p = new MyClass();
		vec.push_back(p); 
	}
	
	//do something with the data
	//and now you are done
	for(vector<MyClass*>::iterator pObj = vec.begin(); pObj != vec.end(); ++pObj){
		delete *pObj; // deletes what pObj is pointing at, a pointer
		
	}
	
	vec.clear(); // purge so no one can delete them again
}