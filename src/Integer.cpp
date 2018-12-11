#include "headers/Integer.h"
#include <iostream>
#include <cctype>

#define DEBUG true


Integer::Integer(){
    this->positive = -1;
}

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

Integer Integer::abs(const Integer& x) {
    const Integer zero = 0;
    if (const_cast<Integer&>(x) > zero) {
        return x;
    }
    else {
        return -const_cast<Integer&>(x);
    }
}

bool Integer::operator==(const Integer& x) {
    return this->positive == x.positive && this->integer == x.integer;
}

bool Integer::operator>(const Integer& x) {
    if (this->positive == x.positive) {
        // signs are same
        if (this->integer.size() > x.integer.size()) {
            // longer number
            return true;
        }
        else if (this->integer.size() < x.integer.size()) {
            return false;
        }
        else {
            bool flag = true;

            int length = x.integer.size();

            auto x_it = x.integer.rbegin();
            auto y_it = this->integer.rbegin();

            while (length >=0) {
                if (*x_it >= *y_it) {
                    flag = false;
                    break;
                }

                length--;
                x_it++;
                y_it++;
            }

            return flag;
        }
    }
    else {
        // signs differ and this is positive
        return this->positive;
    }
}

bool Integer::operator!=(const Integer& x) {
    return !(*this == x);
}

bool Integer::operator<(const Integer& x) {
    return !(*this > x) && *this != x;
}

bool Integer::operator>=(const Integer& x) {
    return (*this > x || *this == x);
}

bool Integer::operator<=(const Integer& x) {
    return (*this < x || *this == x);
}

Integer Integer::operator+(const Integer& x) {
    Integer result;

    if (x.positive && this->positive) {
        if (DEBUG) std::cout << "\nadd::(+,+)";
        result.positive = x.positive & this->positive;

        int length = std::min(this->integer.size(), x.integer.size());

        auto x_it = x.integer.begin();
        auto y_it = this->integer.begin();

        int carry = 0, sum = 0;

        while (length > 0) {
            sum = (*x_it + *y_it + carry) % 10;
            carry = (*x_it + *y_it + carry) / 10;

            result.integer.push_back(sum);

            x_it++;
            y_it++;
            length--;
        }

        if (this->integer.size() >= x.integer.size()) {
            while (y_it != this->integer.end()) {
                sum = (*y_it + carry) % 10;
                carry = (*y_it + carry) / 10;

                result.integer.push_back(sum);
                y_it++;
            }
        }
        else if (this->integer.size() < x.integer.size()) {
            while (x_it != x.integer.end()) {
                sum = (*x_it + carry) % 10;
                carry = (*x_it + carry) / 10;

                result.integer.push_back(sum);
                x_it++;
            }
        }

        if (carry != 0) {
            result.integer.push_back(carry);
        }
    }
    else if (!x.positive) {
        // *this + (-x)
        if (DEBUG) std::cout << "\nadd::(+,-)";
        result = *this - (-*const_cast<Integer*>(&x));
    }
    else if (!this->positive) {
        // x + (-*this)
        if (DEBUG) std::cout << "\nadd::(-,+)";
        result = *const_cast<Integer*>(&x) - *this;
    }
    else {

    }

    return result;
}

Integer Integer::operator-() {
    Integer result = *this;
    result.positive = !result.positive;
    return result;
}

Integer Integer::operator-(const Integer& x) {
    Integer result;

    if (this->positive && !x.positive) {
        // *this - (-x)
        if (DEBUG) std::cout << "\nsub::(+,-)";
        result = *this + (-*const_cast<Integer*>(&x));
    }
    else if (x.positive && !this->positive) {
        // x - (-*this)
        if (DEBUG) std::cout << "\nsub::(-,+)";
        result = -*this + x;
    }
    else {
        if (*this >= x) {
            // *this - x
            if (DEBUG) std::cout << "\nsub::(+,+)::>=";
            result.positive = true;
        }
        else {
            // x - *this
            if (DEBUG) std::cout << "\nsub::(+,+)::<";


            result.positive = false;
        }

        int length = x.integer.size();

        auto x_it = x.integer.begin();
        auto y_it = this->integer.begin();

        int borrow = 0, difference = 0;

        while(length > 0) {
            difference = (*y_it - *x_it - borrow);
            if (difference < 0) {
                borrow = 1;
                difference += 10;
            }
            else {
                borrow = 0;
            }

            result.integer.push_back(difference);

            length--;
            x_it++;
            y_it++;
        }

        while(y_it != this->integer.end()) {
            result.integer.push_back(*y_it - borrow);
            if(borrow > 0) {
                borrow = 0;
            }

            y_it++;
        }
    }

    return result;
}

Integer Integer::operator*(const Integer& x) {
    Integer result;
    return result;
}

Integer Integer::operator/(const Integer& x) {
    Integer result;
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
