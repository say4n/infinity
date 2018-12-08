#ifndef INTEGER_H
#define INTEGER_H
#include <string>
#include <list>

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
        std::list<int> integer;
        bool positive;
};

#endif
