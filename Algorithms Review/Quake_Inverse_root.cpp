#include <iostream>



float fast_root(float number) {
    long i; 
    float x2, y; 
    const float threehalfs = 1.5F; 
    
    x2 = number * 0.5F;
    y = number; 
    i = * (long *) &y;  
    i = 0x5f3759df - (i >> 1); 
    y = * (float * ) &i;
    y = y * (threehalfs - (x2 * y * y)); 
    y = y * (threehalfs - (x2 * y * y)); 
    return y; 
}


using namespace std;
int main(int argc, char *argv[]) {
    std::cout << fast_root(47) << std::endl; 
}