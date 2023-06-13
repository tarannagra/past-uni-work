#include <iostream>

using namespace std;

/* 
    Classes now. The joy of them.
*/

class MyClass { // defines a class for you
    public: // adds a public identifier for all to access these
        string stringer = "stringing"; // public string
        int ten = 10; // public int
        int get_nine() { // returns private int
            return nine;
        }

    private: // adds a private identifer for only the class objects and functions to access
        int nine = 9; // private int
};

int main() {
    MyClass myclass; // initialise class and make object: object -> myclass
    cout << myclass.get_nine() << endl; // returns the value from the private int
    return 0; // returns 0
}