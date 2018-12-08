#include "Integer.h"
#include <iostream>
#include <cctype>

Integer::Integer(int x) {
    if (x>=0) {
        this->positive = true;
    }
    else {
        this->positive = false;
        x = -x;
    }

    if (x == 0) {
        this->integer.push_back(x%10);
    }
    else {
        while (x) {
            this->integer.push_back(x%10);
            x /= 10;
        }
    }
}

Integer::Integer(std::string x) {
    if (x[0] == '-') {
        this->positive = false;

        for (auto digit=x.rbegin(); digit != x.rend(); digit++) {
            char ch = *digit;
            if(isdigit(ch))
                this->integer.push_back(ch - '0');
        }
    }
    else {
        this->positive = true;

        for (auto digit=x.rbegin(); digit != x.rend(); digit++) {
            char ch = *digit;
            if(isdigit(ch))
                this->integer.push_back(ch - '0');
        }
    }

}

Integer Integer::operator+(const Integer& x) {
    Integer result(0);
    return result;
}

Integer Integer::operator-(const Integer& x) {
    Integer result(0);
    return result;
}

Integer Integer::operator*(const Integer& x) {
    Integer result(0);
    return result;
}

Integer Integer::operator/(const Integer& x) {
    Integer result(0);
    return result;
}

std::ostream& operator<<(std::ostream& output, const Integer& x) {
    output << "Integer(" << (x.positive?'+':'-');
    for (auto digit=x.integer.rbegin(); digit !=x.integer.rend(); digit++) {
        output << *digit;
    }
    output << ")" << std::endl;
    return output;
}
