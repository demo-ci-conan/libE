
#include "libE/libE.h"

#include <iostream>
#include "libC/libC.h"

void hello_libC(int indent, const std::string& msg) {
    std::cout << std::string(indent, ' ') << "libE: " << msg << std::endl;
    hello_libC(indent+1, "hello from libE");
}