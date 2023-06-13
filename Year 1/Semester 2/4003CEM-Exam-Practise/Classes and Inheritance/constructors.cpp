#include <iostream>

using namespace std;

/*
    Constructors, building blocks part of OOP.
    Quite weird imo, but they are cool at the same time.
*/

class ContructMe { // defining class
    public: // public access
        ContructMe() { // constructor with the same name as class name
            cout << "You just called me!" << endl; // what will be called when you make the object of the class
        }

        void func() {
            cout << "Hello, from func()" << endl; // sample function i added for clarity below
        }
};

int main() {
    ContructMe cm; // making the object of the class and it calls the constructor
    cm.func(); // calls the func that was made above - to show that the class is behaving normally
               //          and not anything different as with the constructor varient.
    return 0; // return 0
}