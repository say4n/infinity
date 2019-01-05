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
    this->base = Integer(x);
    this->exponent = 0;
}

Float::Float(int base, int exp) {
    this->base = Integer(base);
    this->exponent = Integer(exp);
}

Float Float::operator+(const Float& rhs) {
    Float ret, lhs = *this, trhs = rhs;

    if (lhs.exponent > rhs.exponent) {
        while(lhs.exponent > rhs.exponent) {
            lhs.exponent--;
            lhs.base = lhs.base * 10;
        }

        ret.base = lhs.base + rhs.base;
        ret.exponent = lhs.exponent;
    }
    else if (lhs.exponent < rhs.exponent) {
        while(lhs.exponent < trhs.exponent) {
            trhs.exponent--;
            trhs.base = trhs.base * 10;
        }

        ret.base = lhs.base + trhs.base;
        ret.exponent = trhs.exponent;
    }
    else {
        ret.base = lhs.base + rhs.base;
        ret.exponent = lhs.exponent;
    }

    return ret;
}

Float Float::operator-(const Float& rhs) {
    Float ret, lhs = *this, trhs = rhs;

    if (lhs.exponent > rhs.exponent) {
        while(lhs.exponent > rhs.exponent) {
            lhs.exponent--;
            lhs.base = lhs.base * 10;
        }

        std::cout << lhs.base;
        std::cout << rhs.base;

        ret.base = lhs.base - rhs.base;
        ret.exponent = lhs.exponent;
    }
    else if (lhs.exponent < rhs.exponent) {
        while(lhs.exponent < trhs.exponent) {
            trhs.exponent--;
            trhs.base = trhs.base * 10;
        }

        ret.base = lhs.base - trhs.base;
        ret.exponent = trhs.exponent;
    }
    else {
        ret.base = lhs.base - rhs.base;
        ret.exponent = lhs.exponent;
    }

    return ret;
}

Float Float::operator*(const Float& rhs) {
    Float ret;
    return ret;
}

Float Float::operator/(const Float& rhs) {
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
    output << "e" << (rhs.exponent.isPositive() ? '+':'-');

    for(auto digit = exponent.rbegin(); digit != exponent.rend(); digit++) {
        output << *digit;
    }
    output << ")" << std::endl;

    return output;
};
