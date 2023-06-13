#include <iostream>

using namespace std;

/*
    Inheritance. Like you do it with family.
    Somewhat the same, unless we in a simulation...
*/

class Dog { // defining class called Dog
    public: // adding public variables/funcs
        int x = 10; // public func assigned to 10
        void bark() {
            cout << "Bark!" << endl; // prints "Bark" when called
        }
};

class Animals : public Dog { // defining class called Animals which inherits from the Dog class with public access
    public: // adding the public func
        void is_animal() {
            cout << "yes" << endl; // simple func prints "yes" when called
        }
};

int main() {
    // Defining animals object from class
    Animals animals;
    // Calling .is_animal() from class Animals
    animals.is_animal();
    // Calling .bark() from class Dog which has been inherited
    animals.bark();
    // Returning value of animals.x from class Dog which has been inherited
    cout << animals.x << endl;
    // Incrementing animals.x by + 1
    animals.x++;
    // Returning new value of animals.x which has been incremented by + 1 now
    cout << animals.x << endl;
    return 0;
}