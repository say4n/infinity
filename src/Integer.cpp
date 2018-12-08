#include "Integer.h"
#include <iostream>

Integer::Integer(int x) {
    this->integer = x;
}

Integer::Integer(std::string x) {
    this->integer = std::stoi(x);
}

Integer Integer::operator+(const Integer& x) {
    return Integer( this->integer + x.integer);
}

Integer Integer::operator-(const Integer& x) {
    return Integer( this->integer - x.integer);
}

Integer Integer::operator*(const Integer& x) {
    return Integer(this->integer * x.integer);
}

Integer Integer::operator/(const Integer& x) {
    return Integer(this->integer / x.integer);
}

std::ostream& operator<<(std::ostream& output, const Integer& x) {
    output << "Integer(" << x.integer << ")" << std::endl;
    return output;
}
