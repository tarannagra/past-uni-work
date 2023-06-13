#include <iostream>

using namespace std;

/*
    Multi_Inheritance, almost like going down many generations.
    Parent -> child -> child's child -> child's child's child etc

    Inherit -> 
        Get all the public accessable things and use them in other classes
                which have publically inherited that class.
*/

class Parent { // defines class Parent
    public: // public access functions
        void parent() { 
            cout << "I'm a parent class!" << endl; // prints "I'm a parent class!" when called
        }
};

class Child : public Parent { // defines class Child which publically inherits from class Parent
    public: // public access functions
        void child() {
            cout << "I'm a child class!" << endl; // prints "I'm a child class!" when called
        }
};

class Childs_Child : public Child { // defines class Childs_Child which publically inherits from class Child which inherits from class Parent
    public: // public access functions
        void childs_child() {
            cout << "I'm a child's child class!" << endl; // prints "I'm a child's child class!" when called
        }
};

int main() {
    // Define object cc from Childs_Child class, not any of the others.
    // This is because Childs_Child inherits from Child which inherits from Parent
    Childs_Child cc;
    cc.parent(); // calls from Parent class
    cc.child(); // calls from Child class
    cc.childs_child(); // calls from Childs_Child class
    return 0;
}