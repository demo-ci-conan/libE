
#include "libE/libE.h"

#include <iostream>
#include "libA/libA.h"
#include "libB/libB.h"
#include "libG/libG.h"
#include "libI/libI.h"

void hello_libE(int indent, const std::string& msg) {
    std::cout << std::string(indent, ' ') << "libE: " << msg << std::endl;
    hello_libA(indent+1, "hello from libE");
    hello_libB(indent+1, "hello from libE");
	hello_libG(indent+1, "hello from libE");
	hello_libI(indent+1, "hello from libE");
}