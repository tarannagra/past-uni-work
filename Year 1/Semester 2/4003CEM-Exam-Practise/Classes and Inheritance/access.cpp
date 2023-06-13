#include <iostream>

using namespace std;

/*
    Access Specifiers. They allow you to access certain variables
    and functions only if you have the required `access`...
*/

class Parent {
    public:
        string name = "Generic parent name here"; // publically defining name to the parent
    private:
        int age = 40; // priv8ly defining age to the parent
    protected:
        string occupation = "Laziness :)"; // defining in an inherit-only manner
};

class Child : public Parent { // publically inheriting Parent
    public:
        string get_name() {
            return name; // returning the publically defined name of the Parent 
        }
        string get_occupation() {
            return occupation; // returning the protected occupation of the parent class
                               // It can ONLY be accessed if it has been inherited (line 19)
                               // -> The Child class can access protected variables and functions if
                               // the Child class has inherited the Parent class PUBLICALLY.
        }
        // int get_age() {
        //     return age; // cannot access age as it's private by the Parent class
        // }
};

int main() {
    // Defining the classes and respective objects
    Parent p;
    Child c;
    // Calling parent name
    cout << p.name << endl;
    // Calling the name of the parent class from the child class
    cout << c.get_name() << endl;
    // Calling the occupation of the parent class from the child class
    cout << c.get_occupation() << endl;
    // Cannot get the age of the parent class as it's not available to child and only available for Parent
    // cout << c.get_age() << endl; // will not compile
    return 0;
}