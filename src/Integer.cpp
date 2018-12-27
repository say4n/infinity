#include "headers/Integer.h"
#include <iostream>
#include <cctype>
#include <cassert>

#define DEBUG false


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

Integer Integer::fix_leading_zeros(const Integer& x) {
    Integer result = x;

    while (result.integer.back() == 0 && result.integer.size() > 0) {
        result.integer.pop_back();
    }

    return result;
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

bool Integer::operator==(const Integer& rhs) {
    return this->positive == rhs.positive && this->integer == rhs.integer;
}

bool Integer::operator>(const Integer& rhs) {
    if (this->positive == rhs.positive) {
        // signs are same
        if (this->integer.size() > rhs.integer.size()) {
            // longer number
            return true;
        }
        else if (this->integer.size() < rhs.integer.size()) {
            // shorter number
            return false;
        }
        else {
            // equal length
            bool flag = true;

            int length = rhs.integer.size();

            auto rhs_it = rhs.integer.rbegin();
            auto lhs_it = this->integer.rbegin();

            while (length >=0) {

                if (*lhs_it < *rhs_it) {
                    flag = false;
                    break;
                }

                length--;
                rhs_it++;
                lhs_it++;
            }

            return flag;
        }
    }
    else {
        // signs differ and this is positive
        return this->positive;
    }
}

bool Integer::operator!=(const Integer& rhs) {
    return !(*this == rhs);
}

bool Integer::operator<(const Integer& rhs) {
    return !(*this > rhs) && *this != rhs;
}

bool Integer::operator>=(const Integer& rhs) {
    return (*this > rhs || *this == rhs);
}

bool Integer::operator<=(const Integer& rhs) {
    return (*this < rhs || *this == rhs);
}

Integer Integer::operator+(const Integer& rhs) {
    Integer result;

    if (rhs.positive && this->positive) {
        if (DEBUG) std::cerr << "\nadd::(+,+)";
        result.positive = rhs.positive & this->positive;

        int length = std::min(this->integer.size(), rhs.integer.size());

        auto rhs_it = rhs.integer.begin();
        auto lhs_it = this->integer.begin();

        int carry = 0, sum = 0;

        while (length > 0) {
            sum = (*rhs_it + *lhs_it + carry) % 10;
            carry = (*rhs_it + *lhs_it + carry) / 10;

            result.integer.push_back(sum);

            rhs_it++;
            lhs_it++;
            length--;
        }

        if (this->integer.size() >= rhs.integer.size()) {
            while (lhs_it != this->integer.end()) {
                sum = (*lhs_it + carry) % 10;
                carry = (*lhs_it + carry) / 10;

                result.integer.push_back(sum);
                lhs_it++;
            }
        }
        else if (this->integer.size() < rhs.integer.size()) {
            while (rhs_it != rhs.integer.end()) {
                sum = (*rhs_it + carry) % 10;
                carry = (*rhs_it + carry) / 10;

                result.integer.push_back(sum);
                rhs_it++;
            }
        }

        if (carry != 0) {
            result.integer.push_back(carry);
        }
    }
    else if (!rhs.positive) {
        // *this + (-x)
        if (DEBUG) std::cerr << "\nadd::(+,-)";
        result = *this - (-*const_cast<Integer*>(&rhs));
    }
    else if (!this->positive) {
        // x + (-*this)
        if (DEBUG) std::cerr << "\nadd::(-,+)";
        result = *const_cast<Integer*>(&rhs) - *this;
    }
    else {

    }

    return Integer::fix_leading_zeros(result);
}

Integer Integer::operator-() {
    Integer result = *this;
    result.positive = !result.positive;
    return Integer::fix_leading_zeros(result);
}

Integer Integer::operator-(const Integer& rhs) {
    Integer result;

    if (this->positive && !rhs.positive) {
        // *this - (-rhs)
        if (DEBUG) std::cerr << "\nsub::(+,-)";
        result = *this + (-*const_cast<Integer*>(&rhs));
    }
    else if (rhs.positive && !this->positive) {
        // rhs - (-*this)
        if (DEBUG) std::cerr << "\nsub::(-,+)";
        result = -*this + rhs;
        result.positive = false;
    }
    else {
        if (*this >= rhs) {
            // *this - rhs
            if (DEBUG) std::cerr << "\nsub::(+,+)::>=";
            result.positive = true;
        }
        else {
            // rhs - *this
            if (DEBUG) std::cerr << "\nsub::(+,+)::<";

            result = const_cast<Integer&>(rhs) - const_cast<const Integer&>(*this);
            result.positive = false;

            return Integer::fix_leading_zeros(result);
        }

        int length = rhs.integer.size();

        auto rhs_it = rhs.integer.begin();
        auto lhs_it = this->integer.begin();

        int borrow = 0, difference = 0;

        while(length > 0) {
            difference = (*lhs_it - *rhs_it - borrow);
            if (difference < 0) {
                borrow = 1;
                difference += 10;
            }
            else {
                borrow = 0;
            }

            result.integer.push_back(difference);

            length--;
            rhs_it++;
            lhs_it++;
        }

        while(lhs_it != this->integer.end()) {
            result.integer.push_back(*lhs_it - borrow);
            if(borrow > 0) {
                borrow = 0;
            }

            lhs_it++;
        }
    }

    return Integer::fix_leading_zeros(result);
}

Integer Integer::operator*(const Integer& rhs) {
    int maxlen = rhs.integer.size() + this->integer.size();
    Integer result(std::string(maxlen, '0'));

    result.positive = (this->positive && rhs.positive) || (!this->positive && rhs.positive);

    int offset = 0;

    for(auto mult = rhs.integer.begin(); mult != rhs.integer.end(); mult++) {
        int carry = 0, product = 0, sum;
        auto res_it = result.integer.begin();
        for(int i=0; i<offset; i++)
            res_it++;

        for(auto mpcd = this->integer.begin(); mpcd != this->integer.end(); mpcd++) {

            product = (*mult) * (*mpcd);
            sum = product + carry + *res_it;
            carry = sum/10;
            sum = sum%10;

            if (DEBUG) printf("\n*mult: %d, *mpcd: %d, *res_it: %d, product: %d, sum %d, carry %d, pos: %ld\n", *mult, *mpcd, *res_it, product, sum, carry, std::distance(result.integer.begin(), res_it));

            *res_it = sum;
            res_it++;
        }

        if (carry>0) {
            sum = carry + *res_it;
            carry = sum/10;
            sum = sum%10;

            *res_it = sum;
        }

        offset++;
    }
    return Integer::fix_leading_zeros(result);
}

Integer Integer::operator/(const Integer& rhs) {
    Integer result;

    // DIV_BY_ZERO
    assert(Integer(0) != rhs);

    if (*this < rhs) {
        result = 0;
    }
    else if (Integer(1) == rhs){
        result = *this;
    }
    else {
        // slow division
        Integer tmp = *this;

        while(tmp > rhs) {
            tmp = tmp - rhs;
            result = result + Integer(1);
        }
    }

    return Integer::fix_leading_zeros(result);
}

std::ostream& operator<<(std::ostream& output, const Integer& rhs) {
    output << "Integer(" << (rhs.positive?'+':'-');
    for (auto digit = rhs.integer.rbegin(); digit != rhs.integer.rend(); digit++) {
        output << *digit;
    }
    output << ")" << std::endl;
    return output;
}
