#include <iostream>

using namespace std;

/*
    Macros2, more of an extended part to macros.
*/

#ifndef name // if not defined
#define name "Taran" // define name = "Taran"
#endif // close if statement

#define age 19 // pre define age

#ifdef age // if age defined
#define no_age 99 // define no_age = 99
#endif // close if statement

int main() {
    cout << name << endl; // prints "Taran"
    cout << age << endl; // prints "19"
    cout << no_age << endl; // prints "99"
    return 0; // return 0
}