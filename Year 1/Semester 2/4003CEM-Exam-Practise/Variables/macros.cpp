#include <iostream>

using namespace std;

#define NAME "Taran" // defines a data value without using the string NAME = "aaa"; stuff
#define print_taran

int main() {
    cout << NAME << endl;
    #ifdef print_taran
    cout << "Taran"; // will only print Taran if the value in the ifdef is defined previously
    #endif
    return 0;
}