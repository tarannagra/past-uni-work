#include <iostream>

using namespace std;

/*
    Polymorphism. Uses existing functions to do different stuff.
    Like a magpie, copies but this time changes very slightly.
*/

class Parent { // defining class Parent
    public: // public access functions
        void say() { // creating it's own say function
            cout << "Parent!" << endl;
        }
};

class Child : public Parent {
    public:
        void say() { // creating it's own say function
            cout << "Child from Parent!" << endl;
        }
};

class Childs_Child : public Child {
    public:
        void say() { // creating it's own say function
            cout << "Child's Child from Child!" << endl;
        }
};

int main() {
    /*
        Defining all objects per each class made above
    */
    Parent p;
    Child c;
    Childs_Child cc;
    /*
        Calling the say function from each class.
        Note how it does not replace the function body.
    */
    p.say();
    c.say();
    cc.say();
    // return 0
    return 0;
}