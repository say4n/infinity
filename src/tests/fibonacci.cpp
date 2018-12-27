#include "Integer.h"
#include <iostream>

int main() {
    Integer a = 0;
    Integer b = 1;

    int n = 1000;

    for (int i=0; i<n; i++) {
        Integer t = b;
        b = a + b;
        a = t;
    }

    std::cout << n << "-th fibonacci number = " << b << std::endl;
    //-> 1000-th fibonacci number = Integer(+70330367711422815821835254877183549770181269836358732742604905087154537118196933579742249494562611733487750449241765991088186363265450223647106012053374121273867339111198139373125598767690091902245245323403501)

    return 0;
}
