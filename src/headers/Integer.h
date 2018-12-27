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
*   - Logical
*       -# Comparison (<, >, <=, >=)
*       -# Equality (!=, ==)
*/
class Integer{
    public:
        // Constructors
        Integer();
        Integer(int x);
        Integer(std::string x);

        // Logical operators
        bool operator==(const Integer& x);
        bool operator!=(const Integer& x);
        bool operator>(const Integer& x);
        bool operator<(const Integer& x);
        bool operator>=(const Integer& x);
        bool operator<=(const Integer& x);

        // Arithmetic operators
        Integer operator+(const Integer& x);
        Integer operator-();
        Integer operator-(const Integer& x);
        Integer operator*(const Integer& x);
        Integer operator/(const Integer& x);

        // Stream operators
        friend std::ostream& operator<<(std::ostream &output,
                                        const Integer& x);

        // Static members
        static Integer abs(const Integer& x);
        static Integer fix_leading_zeros(const Integer& x);

    private:
        std::list<int> integer;
        bool positive;
};

#endif
