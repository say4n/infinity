#include "headers/Float.h"
#include <iostream>
#include <cctype>
#include <cassert>

#define DEBUG false

Float::Float() {
    this->base = 0;
    this->exponent = 1;
}

Float::Float(float) {

}

Float::Float(double) {

}

Float::Float(std::string) {

}

Float::~Float() {

}

Float Float::operator+(const Float&) {
    Float ret;
    return ret;
}

Float Float::operator-(const Float&) {
    Float ret;
    return ret;
}

Float Float::operator*(const Float&) {
    Float ret;
    return ret;
}

Float Float::operator/(const Float&) {
    Float ret;
    return ret;
}

std::ostream& operator<<(std::ostream& output, const Float& rhs) {
    output << "Float(";
    for (auto digit = rhs.base.getInteger().rbegin(); digit != rhs.base.getInteger().rend(); digit++) {
        output << *digit;
    }
    output << " e ";
    for (auto digit = rhs.exponent.getInteger().rbegin(); digit != rhs.exponent.getInteger().rend(); digit++) {
        output << *digit;
    }
    output << ")" << std::endl;

    return output;
};
