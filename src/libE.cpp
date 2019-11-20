
#include "libE/libE.h"

#include <iostream>
#include "libB/libB.h"
#include "libG/libG.h"
#include "libI/libI.h"

void hello_libC(int indent, const std::string& msg) {
    std::cout << std::string(indent, ' ') << "libE: " << msg << std::endl;
    hello_libB(indent+1, "hello from libE");
	hello_libG(indent+1, "hello from libE");
	hello_libI(indent+1, "hello from libE");
}