#include "headers/Integer.h"
#include <iostream>
#include <cctype>
#include <cassert>

#define DEBUG false

/**
 * @brief      Basic constructor for Integer class, initialises
 * variable `positive` to undefined (-1) value.
 */
Integer::Integer(){
    this->positive = -1;
}

/**
 * @brief      Constructs an Integer from an int.
 *
 * @param[in]  x     Number as int
 */
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

/**
 * @brief      Constructs Integers from strings. Expects positive
 *  integers as input without a leading `+` sign or negative integers
 * with a leading `-` sign as input string.
 *
 * @param[in]  x     Number represented as string
 */
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

/**
 * @brief      Removes leading zeros from Integer representation. Used
 *  as a utility in the arithmetic operations.
 *
 * @param[in]  x     Integer to remove leading zeros from
 *
 * @return     Integer without leading zeros
 */
Integer Integer::fix_leading_zeros(const Integer& x) {
    Integer result = x;

    while (result.integer.back() == 0 && result.integer.size() > 1) {
        result.integer.pop_back();
    }

    return result;
}

/**
 * @brief      Gets absolute value of an integer.
 *
 * @param[in]  x     Input Integer
 *
 * @return     Absolute value of the Integer being passed
 */
Integer Integer::abs(const Integer& x) {
    const Integer zero = 0;
    if (const_cast<Integer&>(x) > zero) {
        return x;
    }
    else {
        return -const_cast<Integer&>(x);
    }
}

/**
 * @brief      Checks for eqaulity between two Integer objects.
 *
 * @param[in]  rhs   The right hand side of the equality.
 *
 * @return     Returns `true` if both the rhs and lhs are numerically equal,
 * otherwise returns `false`.
 */
bool Integer::operator==(const Integer& rhs) {
    return this->positive == rhs.positive && this->integer == rhs.integer;
}

/**
 * @brief      Checks if left hand side > right hand side.
 *
 * @param[in]  rhs   The right hand side of the inequality.
 *
 * @return     Returns `true` if lhs > rhs, otherwise `false`.
 */
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

/**
 * @brief      Checks for ineqaulity between two Integer objects.
 *
 * @param[in]  rhs   The right hand side of the equality.
 *
 * @return     Returns `true` if the rhs and lhs are not numerically equal,
 * otherwise returns `false`.
 */
bool Integer::operator!=(const Integer& rhs) {
    return !(*this == rhs);
}

/**
 * @brief      Checks if left hand side < right hand side.
 *
 * @param[in]  rhs   The right hand side of the inequality.
 *
 * @return     Returns `true` if lhs < rhs, otherwise `false`.
 */
bool Integer::operator<(const Integer& rhs) {
    return !(*this > rhs) && *this != rhs;
}

/**
 * @brief      Checks if left hand side >= right hand side.
 *
 * @param[in]  rhs   The right hand side of the inequality.
 *
 * @return     Returns `true` if lhs >= rhs, otherwise `false`.
 */
bool Integer::operator>=(const Integer& rhs) {
    return (*this > rhs || *this == rhs);
}

/**
 * @brief      Checks if left hand side <= right hand side.
 *
 * @param[in]  rhs   The right hand side of the inequality.
 *
 * @return     Returns `true` if lhs <= rhs, otherwise `false`.
 */
bool Integer::operator<=(const Integer& rhs) {
    return (*this < rhs || *this == rhs);
}

/**
 * @brief      Addition of two Integer objects
 *
 * @param[in]  rhs   The right hand side
 *
 * @return     Sum of the left hand side and the right hand side.
 */
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

/**
 * @brief      Pre increment an Integer object.
 */
void Integer::operator++() {
    *this = Integer::fix_leading_zeros(*this + Integer(1));
}

/**
 * @brief      Pre decrement an Integer object.
 */
void Integer::operator--() {
    *this = Integer::fix_leading_zeros(*this - Integer(1));
}

/**
 * @brief      Post increment an Integer object.
 *
 * @param[in]  <unnamed>  Postfix, used internally
 */
void Integer::operator++(int) {
    *this = Integer::fix_leading_zeros(*this + Integer(1));
}

/**
 * @brief      Post decrement an Integer object.
 *
 * @param[in]  <unnamed>  Postfix, used internally
 */
void Integer::operator--(int) {
    *this = Integer::fix_leading_zeros(*this - Integer(1));
}

/**
 * @brief      Unary neagtion of an Integer object. Flips the `positive`
 *  flag of the Integer object for non-zero Integer objects.
 *
 * @return     Negative of passed Integer.
 */
Integer Integer::operator-() {
    Integer result = *this;
    if(result != Integer(0))
        result.positive = !result.positive;
    return Integer::fix_leading_zeros(result);
}

/**
 * @brief      Subtraction of two Integer objects
 *
 * @param[in]  rhs   The right hand side
 *
 * @return     Result of subtraction of the right hand side from
 *  the left hand side.
 */
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

/**
 * @brief      Multiplication of two Integer objects
 *
 * @param[in]  rhs   The right hand side
 *
 * @return     Product of the left hand side and the right hand side.
 */
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

/**
 * @brief      Quotient of division of two Integer objects
 *
 * @param[in]  rhs   The right hand side
 *
 * @return     Quotient of the division of the left hand side by
 *  the right hand side.
 */
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
            result++;
        }
    }

    return Integer::fix_leading_zeros(result);
}

/**
 * @brief      Remainder of division of two Integer objects
 *
 * @param[in]  rhs   The right hand side
 *
 * @return     Remainder of the division of the left hand side by
 *  the right hand side.
 */
Integer Integer::operator%(const Integer& rhs) {
    Integer result;

    // DIV_BY_ZERO
    assert(Integer(0) != rhs);

    // POSITIVE_MOD
    assert(Integer(0) < rhs);
    assert(Integer(0) < *this);

    if (*this < rhs) {
        result = *this;
    }
    else if (Integer(1) == rhs){
        result = Integer(0);
    }
    else {
        // slow division
        Integer tmp = *this;

        while(tmp > rhs) {
            tmp = tmp - rhs;
            result++;
        }

        result = tmp;

        if (result > const_cast<Integer&>(rhs) - result) {
            result = const_cast<Integer&>(rhs) - result;
        }
    }

    return Integer::fix_leading_zeros(result);
}

/**
 * @brief      Raise base exponent times
 *
 * @param[in]  base      The base
 * @param[in]  exponent  The exponent
 *
 * @return     The result of exponentiation (base ^ exponent)
 */
Integer Integer::pow(const Integer& base, const Integer& exponent) {
    Integer result = Integer(1);

    assert(Integer(0) <= exponent);

    if (Integer(0) == exponent) {
        result = Integer(1);
    }
    else if (Integer(1) == exponent) {
        result = base;
    }
    else {
        Integer tmp = exponent;
        Integer div_by_two = tmp % 2;

        Integer new_exp = tmp / 2;
        result = Integer::pow(base, new_exp) * Integer::pow(base, new_exp);

        if (div_by_two != 0) {
            result = result * base;
        }
    }

    return result;
}


/**
 * @brief      Prints an Integer object to the stream `output`
 *
 * @param      output  The output stream where the Integer object will be printed to
 * @param[in]  rhs     The right hand side of the expression
 *
 * @return     The output stream for the Integer obbject
 */
std::ostream& operator<<(std::ostream& output, const Integer& rhs) {
    output << "Integer(" << (rhs.positive?'+':'-');
    for (auto digit = rhs.integer.rbegin(); digit != rhs.integer.rend(); digit++) {
        output << *digit;
    }
    output << ")" << std::endl;
    return output;
}
