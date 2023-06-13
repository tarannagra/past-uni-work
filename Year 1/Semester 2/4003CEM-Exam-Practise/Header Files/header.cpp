#include <iostream>
#include "header.h" // this is the header file I have made

using namespace std;
using namespace Header; // made a namespace from the header file and now accessing it

int main() {
    MyHeader mh; // taking the class and defining an object
    cout << mh.name << endl; // prints "this is my header name"
    cout << mh.age << endl; // prints "19"
}