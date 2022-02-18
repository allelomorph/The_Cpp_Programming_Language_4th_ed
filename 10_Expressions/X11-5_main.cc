#include <iostream>
#include <limits>


int main() {
    // OS: Ubuntu 20.04.3 LTS
    // Compiler: g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

    // Compile time: no g++ warnings for [over|under]flow even with all turned on
    // Run time: values [over|under]flow without consequence, programmer must
    //   keep track of possibility of data corruption

    int i {std::numeric_limits<int>::max()};
    std::cout << "std::numeric_limits<int>::max() (" << i << ") + 1: " << i + 1;
    if (i + 1 == std::numeric_limits<int>::min())
        std::cout << " (overflows to INT_MIN)";
    std::cout << std::endl;

    i = std::numeric_limits<int>::min();
    std::cout << "std::numeric_limits<int>::min() (" << i << ") - 1: " << i - 1;
    if (i - 1 == std::numeric_limits<int>::max())
        std::cout << " (underflows to INT_MAX)";
    std::cout << std::endl;

    // Compile time: using `g++ -Wall -Werror -Wextra -pedantic -std=c++11`,
    //   dividing by zero results in -Werror=div-by-zero; must use -Wno-div-by-zero
    // Run time: results in floating-point exception (Linux kernel exception,
    //   not c++ exception) and termination with SIGFPE
    std::cout << "1 / 0: " << 1 / 0 << std::endl;
}
