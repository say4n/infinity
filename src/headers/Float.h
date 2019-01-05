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
        Float(float);
        Float(double);
        Float(std::string);
        ~Float();

        Float operator+(const Float&);
        Float operator-(const Float&);
        Float operator*(const Float&);
        Float operator/(const Float&);

        friend std::ostream& operator<<(std::ostream&, const Float&);

    private:
        Integer base, exponent;
};

#endif
