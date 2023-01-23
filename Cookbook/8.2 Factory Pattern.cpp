#include <iostream>

using namespace std;

class Session{};
class SessionFactory{
public:
	Session Create();
	Session* CreatePtr();
	void Create(Session*& p); 
};

//return a copy of the stack object
Session SessionFactory::Create(){
	Session s; 
	return s; 
}
//returns a pointer to a heap object
Session* SessionFactory::CreatePtr(){
	return(new Session()); 
}

//update the caller's pointer with the address of a new object
void SessionFactory::Create(Session*& p) {
	p = new Session(); 
}

static SessionFactory f; // the one factory object

int main(int argc, char *argv[]) {
	Session* p1;
	Session* p2; new Session();
	
	*p2 = f.Create(); //assign the object return from Create
	p1 = f.CreatePtr(); // or return a pointer to a heap object
	f.Create(p1); //update pointer with new address
}