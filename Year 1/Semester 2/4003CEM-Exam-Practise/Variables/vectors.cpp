#include <iostream>
#include <vector> // adding vector library for vector support :p

using namespace std;

/*
    Vectors to store elements of the similar data types it holds.
    Not like arrays with a defined amount of elements,
    it can have any number of elements and can grow massive :o
*/

int main() {
    std::vector<int> vector_name; // defining the variable vector_name 
    // vector can also be defined without the std:: as the namespace is already used (line 4)
    vector_name = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // adding elements to the vector made on line 13
    cout << vector_name[1] << endl; // outputting the second element in the vector -> remember numbers in computers start at 0! 

    // Iterating through the vector
    for (const int& x : vector_name) { // defining x as a reference variable
        cout << x << " "; // printing out each element of the vector and spacing it out 
    }
    return 0; // return 0
}