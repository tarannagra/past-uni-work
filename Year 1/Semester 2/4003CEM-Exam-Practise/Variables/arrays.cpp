#include <iostream>
#include <array>

using namespace std;

/*
    Arrays < Vectors. Flexibility > Not Flexible

*/


int main() {
    string myArray[3]; // define new array - data-type string, element size of 3
    // assigning elements to index 0, 1, and 2
    myArray[0] = "C++"; 
    myArray[1] = "Has"; 
    myArray[2] = "Arrays";
    // printing out each element 
    cout << myArray[0] << " " << myArray[1] << " " << myArray[2] << endl;

    for (const string& x: myArray) { // looping through the array 
        cout << x << " "; // printing out each element seperated by a space
    }
    cout << "\n";

    // Making arrays a different way
    // using the template format
    array<int, 5> myOtherArray = {1, 2, 3, 4, 5};
    // same process of getting elements, just don't need to define elements after as already done as such
    for (const int& x : myOtherArray) { // looping through the array again
        cout << x << " ";
    }
    cout << "\n";
}