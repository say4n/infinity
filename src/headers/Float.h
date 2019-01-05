/**
*   @file Integer.h
*   @author Sayan Goswami
*
*   Arbitrary precison floating point numbers
*/

#ifndef FLOAT_H
#define FLOAT_H

#include "Integer.h"

class Float {
    public:
        Float();
        Float(int);
        Float(int, int);

        Float operator+(const Float&);
        Float operator-(const Float&);
        Float operator*(const Float&);
        Float operator/(const Float&);

        friend std::ostream& operator<<(std::ostream&, const Float&);

    private:
        Integer base, exponent;
};

#endif
