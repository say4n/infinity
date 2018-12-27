#include "Integer.h"
#include <iostream>

int main() {
    Integer x = 1;
    Integer result = 1;

    int n = 100;

    for (int i=0; i<n; i++) {
        result = result * x;
        x++;
    }

    std::cout << n << "! = " << result << std::endl;
    //-> 100! = Integer(+93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000)

    return 0;
}
