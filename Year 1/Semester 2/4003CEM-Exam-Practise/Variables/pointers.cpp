#include <iostream>

using namespace std;

/*
    Pointers. They are the death of me.
    They are variables that hold memory addresses of other variables.
*/

int main() {
    // normal variable
    int get_my_address = 10; 
    // outputting normal variable
    cout << get_my_address << endl;
    // outputting memory address of the variable
    cout << &get_my_address << endl;

    // pointer variable
    // int *point;
    // or can be wrote as:
    // int* point;
    // define potiner and normal variable (pointer -> point, normal -> p)
    int* point, p;
    p = 1010; // assign a value to variable p
    point = &p; // pointer and add reference to p
    cout << *point << endl; // return point value       NOTE: *point in cout, must be *point or it returns address
    delete point; // remember to delete to prevent memory leaks
    return 0;
}