#include "Float.h"
#include <iostream>

int main() {
    Float x(4, 1);
    Float y(123, -1);

    std::cout << x;
    std::cout << y;

    std::cout << "x + y :: " << x + y;
    std::cout << "x - y :: " << x - y;

    return 0;
}
