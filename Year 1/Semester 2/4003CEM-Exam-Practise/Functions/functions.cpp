#include <iostream>

using namespace std;

/*
    Functions can be a value returner or can return nothing.
    If they return a value, they must be created specifying the value they will return.

    If they don't need to return anything, they should specify a return type of void.
*/

int int_function(int x) { // requires an argument
    x+=1;
    return x; // returns int value which has been incremented by +1
}

void fuckery(string fuckery_string) {
    cout << fuckery_string << endl; // just console outputs the fuckery string you passed
    return; // possible to have a return, but cannot return a value
}

int main() {
    // this is a function, the main function
    cout << int_function(10) << endl; // this console outputs 11 as it is 10+1, run it to find out
    fuckery("fuck");
    return 0;
}