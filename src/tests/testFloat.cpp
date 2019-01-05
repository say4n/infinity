#include "Float.h"
#include <iostream>

int main() {
    Float x(4, -2);
    Float y(123, -1);

    std::cout << "x :: " << x;
    std::cout << "y :: " << y;

    std::cout << "x + y :: " << x + y;
    std::cout << "x - y :: " << x - y;

    return 0;
}
