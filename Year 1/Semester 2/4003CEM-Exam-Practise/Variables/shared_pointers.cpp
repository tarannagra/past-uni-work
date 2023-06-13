#include <iostream>
#include <memory> // required for std::shared_ptr

using namespace std;

/*
    Shared Pointers. Sharing the way you point?
    They actually smart pointers (see smart_pointers.cpp)
    which keep the ownership of an object even though it's a pointer.
    Multiple shared pointers can have ownership of the same object making them flexible.
    When a shared pointer is automatically deallocated, it makes use of the delete keyword
    you would normally use when releasing the memory of a manual-made pointer. Quite good!
*/

int main() {
    // Making a new shared pointer, variable name sp_int, value is 10
    // new int(10) makes a new integer value 10
    shared_ptr<int> sp_int(new int(10));
    cout << sp_int << endl; // this will print a memory address as we have not printed the pointer value of it
    cout << *sp_int << endl; // now this will print 10, as it's the pointer value as defined on line 20
    
    // Making a new empty pointer
    shared_ptr<int> sharedPtr;
    cout << sharedPtr << endl; // will show a memory address but it has no value in it anyways, printing will show 0
    // Making a new shared pointer, this time as a float with the value of 124.0564
    shared_ptr<float> sharedPtr1(new float(124.0564));
    cout << sharedPtr1 << endl; // will show a memory address of variable sharedPtr1
    cout << *sharedPtr1 << endl; // will show the value of the float in sharedPtr1

    return 0;
}