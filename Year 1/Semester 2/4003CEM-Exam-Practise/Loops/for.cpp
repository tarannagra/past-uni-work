#include <iostream>

#ifdef _WIN32 // if os is windows
#include "Windows.h" // include Windows.h for sleep method
#endif // end the if

#ifdef linux // if os is linux
#include "unistd.h" // include unistd.h for sleep method
#endif // end the if

#define sleep_time 100 // define macro to sleep for 500 milliseconds (1/2 a second)

using namespace std;

/*
    For loops. Iteration over a certain amount of times / elements.
    They are used for a lot of shit, can be used for bad stuff too.
*/

void for_loop(int max) {
    for (int x = 1; x <= max; x++) { // defining new int called x. stop when x is less than or equal to int max. increment x by 1
        cout << x << " "; // print out each number with a space "1 2 3 etc"
        Sleep(sleep_time); // making use of a define variable at line 11
    }
    cout << "\n"; // new line if you don't want the next lines of code on same line 
}

int main() {
    for_loop(10); // calling the for loop and setting the max to be 10 in this example
    for_loop(100); // calling the for loop and setting the max to now being 100!
    return 0;
}