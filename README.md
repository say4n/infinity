<h2 align="center">
    <img src="https://cdn.jsdelivr.net/gh/Sayan98/infinity@latest/assets/infinity.svg" height=200 alt="infinity: an arbitrary precision arithmetic library">
    <br>a signed arbitrary precision arithmetic library<br>
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
    - [integer](#integer)
    - [float](#float)
4. [warning](#warning)
5. [author](#author)

## usage

1. Build `libInfinity.a` using `make all` in the `src` directory.
2. Copy the header files and `libInteger.a` file to your project.
3. Include the header files as per requirement in your source file.
4. Compile with `-L$(LIB)` and `-lInfinity` flags where `LIB` is the directory where `libInfinity.a` resides in.


## tests

Run `make testInteger` in the `src` directory to compile the sanity checks. Execute the generated executable with `./test.out`.


## example

### integer

```cpp
#include <iostream>
#include "Integer.h"

int main() {
    Integer a("80");
    Integer b("4");
    Integer c = 11;
    Integer d = 100;

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
d :: Integer(+100)
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
Integer::pow(c, d) :: Integer(+137806123398222701841183371720896367762643312000384664331464775521549852095523076769401159497458526446001)
```

### float

work in progress


## warning
This a pet project to explore arbitrary precision arithmetic. If you need arbitrary precision arithmetic, consider using something more mature like [GMP](https://gmplib.org).


## author
Sayan Goswami (c) 2018


