#ifndef INTEGER_H
#define INTEGER_H
#include <string>

class Integer{
    public:
        Integer(int x);
        Integer(std::string x);
        Integer operator+(const Integer& x);
        Integer operator-(const Integer& x);
        Integer operator*(const Integer& x);
        Integer operator/(const Integer& x);
        friend std::ostream& operator<<(std::ostream &output,
                                        const Integer& x);
    private:
        int integer;
};

#endif
