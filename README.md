# SpeckSmartPointer
SpeckPointer is a custom shared pointer implementation in C++ designed for automatic memory management and thread-safe reference counting.

## Build Instructions
To build this project follow these steps:
1. Clone the repository
    ```bash
    git clone https://github.com/yourusername/speck_pointer.git
    cd speck_pointer
    ```
2.  Create a build directory and configure project using CMake
    ```bash
    mkdir build
    cd build
    cmake .. <CMake options>
    ```
3. Build the project
    ```bash
    make
    ```
4. Run the test program
    ```bash
    ./test_speck_pointer
    ```
## How to use
Using `speck_pointer` is very similar to using `std::shared_ptr`. 

```cpp
#include "speck_pointer.hpp"
#include <iostream>
#include <string>

struct foo {
    std::string text;

    foo(const std::string &content) : text(content) {}

    ~foo() { }
};

int main(void) {

    // Using the primary constructor for primitive types
    speck::speck_pointer<int> p1(new int(42));
    speck::speck_pointer<int> p2 = p1;

    // Using the "make_speck_pointer" function for dynamically allocated objects
    speck::speck_pointer<foo> fPtr = speck::make_speck_pointer<foo>("Hello World");


    return 0;
}
```

## References
```link
https://betterprogramming.pub/understanding-smart-pointer-iii-909512a5eb05
```
