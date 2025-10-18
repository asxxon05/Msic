#include <iostream>

using namespace std;    

struct Msic
{
    int data;
    Msic(int val) : data(val) {}

};


int main(){
    Msic obj(42);
    cout << "Msic data: " << obj.data << endl;
    
return 0;
}