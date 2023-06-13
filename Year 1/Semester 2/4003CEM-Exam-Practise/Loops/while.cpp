#include <iostream>

using namespace std;

/*
    While loops. Can also be known as a forever loop.
    Breaks only when a condition is met; usually a boolean.
*/

void while_loop(int max) {
    int y = 0; // define variable to increment and match condition
    while (y < max) { // condition when to stop:: when y is less than max, be false - stop
        cout << y << " "; // iterate over it and print with a space after the number
        y++; // increment by + 1
    }
}

int main() {
    while_loop(10); // calling function, param -> max which will be in the condition of the while loop
    return 0;
}