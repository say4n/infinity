/**
*   @file Integer.h
*   @author Sayan Goswami
*
*   Arbitrary precison integers
*/
#ifndef INTEGER_H
#define INTEGER_H
#include <string>
#include <list>

/** \brief Arbitrary precision Integer arithmetic and logical operations.
*
*   Supported operations:
*   - Arithmetic
*       -# Addition
*       -# Subtraction
*       -# Multiplication
*       -# Division
*       -# Negation
 *      -# Exponentiation
*   - Logical
*       -# Comparison (<, >, <=, >=)
*       -# Equality (!=, ==)
*/
class Integer{
    public:
        // Constructors
        Integer();
        Integer(int);
        Integer(std::string);

        // Relational operators
        bool operator==(const Integer&);
        bool operator!=(const Integer&);
        bool operator>(const Integer&);
        bool operator<(const Integer&);
        bool operator>=(const Integer&);
        bool operator<=(const Integer&);

        // Arithmetic operators
        /// Unary
        Integer operator-();
        //// prefix
        void operator++();
        void operator--();
        //// postfix
        void operator++(int);
        void operator--(int);
        /// Binary
        Integer operator+(const Integer&);
        Integer operator-(const Integer&);
        Integer operator*(const Integer&);
        Integer operator/(const Integer&);
        Integer operator%(const Integer&);

        // Bitwise operators
        friend std::ostream& operator<<(std::ostream&, const Integer&);

        // Static members
        static Integer abs(const Integer&);
        static Integer fix_leading_zeros(const Integer&);
        static Integer pow(const Integer&, const Integer&);

    private:
        std::list<int> integer;
        bool positive;
};

#endif
