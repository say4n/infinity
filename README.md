<h2 align="center">
    <img src="https://cdn.jsdelivr.net/gh/Sayan98/infinity@latest/assets/infinity.svg" height=200 alt="infinity: an arbitrary precision integer arithmetic library">
    <br>an arbitrary precision integer arithmetic library<br>
<h2>

<h5 align="center">
<img src="https://forthebadge.com/images/badges/made-with-c-plus-plus.svg" height=30>
<img src="https://forthebadge.com/images/badges/you-didnt-ask-for-this.svg" height=30>
</h5>

**infinity**, as of present, is by no means a replacement for any serious work, it is a weekend hack at best. Please proceed with extreme caution. You have been warned!

## usage

1. Build `libInteger.a` using `make all` in the `src` directory.
2. Copy the `Integer.h` and `libInteger.a` file to your project.
3. Include `Integer.h` in your source file.
4. Compile with `-L$(LIB)` and `-lInteger` flags where `LIB` is the directory where `libInteger.a` resides in.


## tests

Run `make test` in the `src` directory to compile the sanity checks. Execute the generated executable with `./test.out`.


## example

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


