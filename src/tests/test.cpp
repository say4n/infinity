#include "Integer.h"
#include <iostream>

int main() {
    Integer a("80");
    Integer b("4");
    Integer c = 11;
    Integer d = 40;

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

    std::cout << "-a :: " << -a;
    std::cout << "a + b :: " << a + b;
    std::cout << "a - b :: " << a - b;
    std::cout << "a * b :: " << a * b;
    std::cout << "a / b :: " << a / b;
    std::cout << "a % b :: " << a % b;
    std::cout << "Integer::pow(c, d) :: " << Integer::pow(c, d);

    return 0;
}
