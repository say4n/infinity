# infinity
arbitrary precision integer arithmetic

## usage

```cpp
#include <iostream>
#include "Integer.h"

int main() {
    Integer a("199999999999999999999999999999999999999999999999");
    Integer b("999999999999999999999999999999999999999999999999");
    Integer c = -319879352;
    Integer d ("-141241241241");

    // Integers
    std::cout << "a :: " << a;
    std::cout << "b :: " << b;
    std::cout << "c :: " << c;
    std::cout << "d :: " << d;

    // logical ops
    std::cout << "a <= b :: " << (a <= b) << std::endl;
    std::cout << "a < b :: " << (a < b) << std::endl;
    std::cout << "a >= b :: " << (a >= b) << std::endl;
    std::cout << "a > b :: " << (a > b) << std::endl;
    std::cout << "a == b :: " << (a == b) << std::endl;
    std::cout << "a != b :: " << (a != b) << std::endl;

    // arithmetic ops
    std::cout << "-a :: " << -a;
    std::cout << "a + b :: " << a + b;
    std::cout << "a - b :: " << a - b;
    std::cout << "a * b :: " << a * b;
    std::cout << "a / b :: " << a / b;

    return 0;
}
```

## warning
This a pet project to explore arbitrary precision integers. If you need arbitrary precision arithmetic, consider using something more mature like [GMP](https://gmplib.org).

## author
Sayan Goswami (c) 2018


