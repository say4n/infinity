<h2 align="center">
    <img src="https://cdn.jsdelivr.net/gh/Sayan98/infinity@latest/assets/infinity.svg" height=200 alt="infinity: an arbitrary precision integer arithmetic library">
    <br>a signed arbitrary precision integer arithmetic library<br>
<h2>

<h5 align="center">
<img src="https://forthebadge.com/images/badges/made-with-c-plus-plus.svg" height=30>
<img src="https://forthebadge.com/images/badges/you-didnt-ask-for-this.svg" height=30>
</h5>

**infinity**, as of present, is by no means a replacement for any serious work, it is a weekend hack at best. Please proceed with extreme caution. You have been warned!

## contents
1. [usage](#usage)
2. [tests](#tests)
3. [example](#example)
4. [warning](#warning)
5. [author](#author)

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
    Integer a("80");
    Integer b("4");
    Integer c = 11;
    Integer d = 40;

    std::cout << "a :: " << a;
    std::cout << "b :: " << b;
    std::cout << "c :: " << c;
    std::cout << "d :: " << d;

    std::cout << "a <= b :: " << (a <= b) << std::endl;
    std::cout << "a < b :: " << (a < b) << std::endl;
    std::cout << "a >= b :: " << (a >= b) << std::endl;
    std::cout << "a > b :: " << (a > b) << std::endl;
    std::cout << "a == b :: " << (a == b) << std::endl;
    std::cout << "a != b :: " << (a != b) << std::endl;

    std::cout << "-a :: " << -a;
    std::cout << "a + b :: " << a + b;
    std::cout << "a - b :: " << a - b;
    std::cout << "a * b :: " << a * b;
    std::cout << "a / b :: " << a / b;
    std::cout << "a % b :: " << a % b;
    std::cout << "Integer::pow(c, d) :: " << Integer::pow(c, d);

    return 0;
}
```

Which results in:
```bash
a :: Integer(+80)
b :: Integer(+4)
c :: Integer(+11)
d :: Integer(+40)
a <= b :: 0
a < b :: 0
a >= b :: 1
a > b :: 1
a == b :: 0
a != b :: 1
-a :: Integer(-80)
a + b :: Integer(+84)
a - b :: Integer(+76)
a * b :: Integer(+320)
a / b :: Integer(+20)
a % b :: Integer(+0)
Integer::pow(c, d) :: Integer(+452592555681759518058893560348969204658401)
```


## warning
This a pet project to explore arbitrary precision integers. If you need arbitrary precision arithmetic, consider using something more mature like [GMP](https://gmplib.org).


## author
Sayan Goswami (c) 2018


