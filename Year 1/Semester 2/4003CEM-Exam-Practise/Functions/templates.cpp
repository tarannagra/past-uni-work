#include <iostream>

using namespace std;

/*
    Templates. They are complex to look at.
*/

template<class T> T add(T &x, T &y) { // template to make a function to add numbers
    // the T means type meaning that the values of the parameters can be any data-type
    // &x, &y are references to values that can be anything -> float, int, long, double etc
    T result = x + y; // makes a return variable from the T class part; can be anything 
    //                   -> is now dynamically typed as it will find itself on runtime not beforehand
    return result; // return the result
}


int main() {
    // as the add function takes in variable references, it needs explicitily defined variables to reference.
    // it does not work if you just use `cout << add(1, 3) << endl;`
    // for templates, it requires references to variables
    int x = 10;
    int y = 100;
    float xx = 100.100;
    float yy = 10.10;
    cout << add(x, y) << endl;
    cout << add(xx, yy) << endl; // the variables MUST be the same data-type and cannot be different.
    // cannot have int + float or double + int
    return 0;
}