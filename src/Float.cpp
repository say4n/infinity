#include "headers/Float.h"
#include <iostream>
#include <cctype>
#include <cassert>
#include <list>

#define DEBUG false

Float::Float() {
    this->base = 0;
    this->exponent = 0;
}

Float::Float(int x) {
    this->base = x;
    this->exponent = 0;
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
    output << "Float(" << (rhs.base.isPositive() ? '+':'-');
    std::list<int> base = rhs.base.getInteger();
    std::list<int> exponent = rhs.exponent.getInteger();


    for(auto digit = base.rbegin(); digit != base.rend(); digit++) {
        output << *digit;
    }
    output << "e" << (rhs.base.isPositive() ? '+':'-');

    for(auto digit = exponent.rbegin(); digit != exponent.rend(); digit++) {
        output << *digit;
    }
    output << ")" << std::endl;

    return output;
};
