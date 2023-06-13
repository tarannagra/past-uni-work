#include <iostream>

using namespace std;

int main() {
    char this_is_a_char = 'a';
    std::string this_is_a_string = "this is a string"; // as we are using namespace std; don't need to use std::
    int this_is_an_int = 10;
    bool this_is_false = false;
    double this_is_a_double = 1.24;
    float this_is_a_float = 1.34;

    // You can console output these with the following:
    //      I will not do it for all as that's aids.

    cout << this_is_a_char << endl;

    return 0;
}