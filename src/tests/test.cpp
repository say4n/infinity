#include "Integer.h"
#include <iostream>

int main() {
    Integer a("99");
    Integer b("99");
    Integer c = -323432;
    Integer d ("-141241241241");

    std::cout << "a :: " << a;
    std::cout << "b :: " << b;
    std::cout << "c :: " << c;
    std::cout << "d :: " << d;

    std::cout << "a <= b :: " << (a <= b) << std::endl;
    std::cout << "a < b :: " << (a < b) << std::endl;
    std::cout << "a >= b :: " << (a >= b) << std::endl;
    std::cout << "a > b :: " << (a > b) << std::endl;
    std::cout << "a == b :: " << (a == b) << std::endl;
    std::cout << "a != b :: " << (a != b) << std::endl;

    std::cout << "a + b :: " << a + b;
    std::cout << "a - b :: " << a - b;
    std::cout << "a * b :: " << a * b;
    std::cout << "a / b :: " << a / b;

    return 0;
}
