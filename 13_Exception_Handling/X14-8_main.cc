#include <iostream>
#include <cstdlib>  // abort

int main() {
    try {
        // main body from task description:
        /* ... */
        // Example exception to illustrate (can't instantiate a std::exception,
        //   only derived classes):
        throw std::runtime_error ("`.what()` message");
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        abort();
    }
}
