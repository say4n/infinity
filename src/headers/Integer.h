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
        Integer();
        Integer(int x);
        Integer(std::string x);

        bool operator==(const Integer& x);
        bool operator!=(const Integer& x);
        bool operator>(const Integer& x);
        bool operator<(const Integer& x);
        bool operator>=(const Integer& x);
        bool operator<=(const Integer& x);
        Integer operator+(const Integer& x);
        Integer operator-();
        Integer operator-(const Integer& x);
        Integer operator*(const Integer& x);
        Integer operator/(const Integer& x);

        friend std::ostream& operator<<(std::ostream &output,
                                        const Integer& x);
    private:
        std::list<int> integer;
        bool positive;
};

#endif
