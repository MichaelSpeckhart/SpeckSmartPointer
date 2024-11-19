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
#include "unique_pointer.h"
#include <iostream>
#include <string>

struct Foo {
    std::string text;

    Foo(const std::string &content) : text(content) {}

    ~Foo() { }
};

int main(void) {

    // Using the primary constructor for primitive types
    speck::unique_pointer<int> p1(new int(42));

    // Using the speck::make_unique for dynamic objects
    speck::unique_pointer<Foo> foo_ptr = speck::make_unique<Foo>("Hello World");

    return 0;
}
```

## References
```link
https://betterprogramming.pub/understanding-smart-pointer-iii-909512a5eb05
```
