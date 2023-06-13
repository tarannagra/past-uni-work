#include <iostream>

using namespace std;

/*
    Do while. A while loop with do.
    It's literally this ^^^.
*/

void do_while_loop(int max) {
    int x = 0; // define variable to increment and match condition
    do { // commence the code block
        cout << x << " "; // iterate over it and print with a space after the number
        x++; // increment by + 1
    } while (x < max); // while condition (same as while.cpp)
}

int main() {
    do_while_loop(10); // calling function (you will know what max is by now I'm sure)
    return 0;
}