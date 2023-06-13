#include <iostream>
#include <memory.h>
#include <memory>

using namespace std;

/*
    Smart Pointers. Pointing you in the smart way!
    They are the same as shared pointers (see shared_pointers.cpp)
    They prevent memory leaks and automatically deallocate memory when needed.
*/

void memory_leak() {
    // This causes a memory leak for the following reasons:
    // myPointer is assigned -> memory assigned to this variable
    // myPointer is never actually used and thus memory is sitting and waiting
    // myPointer is not deallocated from it's memory and results in memory leakage.
    int* myPointer = new int(10);
    int x = 15;
    if (x == 15) {
        return;
    }
    delete myPointer; // NEED TO DO THIS OR MEMORY LEAK
    // this delete statement will never be met if x == 15 though thus memory leakage again.
}

void no_memory_leak() {
    unique_ptr<int> myPointer(new int(10)); // makes a new pointer, value of 10 to it
    // note it's a unique pointer and not a normal one, check main func for more info.
    int x = 15;
    if (x == 15) {
        return; // no more memory leakage as the smart pointer knows how to handle if it's not used and when to deallocate the memory
        // smart, eh?
    }
}

int main() {
    // Note: They are not called smart pointer, rather unique pointers. 
    // Any keywords of them will point `:p` to smart pointers.
    memory_leak(); // will cause memory leak!
    no_memory_leak(); // no memory leak!

    return 0;
}