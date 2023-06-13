#pragma once // ensures that the header file is only included once and not all the time during compiling

#ifndef HEADER // if not defined
#define HEADER // define HEADER

#include <iostream>

namespace Header { // defines the header for the main file to "using namespace " stuff
    class MyHeader { // define header
        public: // public access identifier
            std::string name = "this is my header name"; // makes a variable called name
            int age = 19; // makes a variable assigned to int 19
    };
}

#endif // end the ifndef at line 3