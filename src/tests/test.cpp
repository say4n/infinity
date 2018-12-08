#include "Integer.h"
#include <iostream>

int main() {
    Integer a("3894621856738568137500000000022000000");
    Integer b("16630000001432");
    Integer c = -323432;
    Integer d ("-141241241241");

    std::cout << "a :: " << a;
    std::cout << "b :: " << b;
    std::cout << "c :: " << c;
    std::cout << "d :: " << d;

    std::cout << "a + b :: " << a + b;
    std::cout << "a - b :: " << a - b;
    std::cout << "a * b :: " << a * b;
    std::cout << "a / b :: " << a / b;

    return 0;
}
