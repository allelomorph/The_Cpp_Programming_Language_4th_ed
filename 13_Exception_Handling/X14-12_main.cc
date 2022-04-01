#include <iostream>
#include <chrono>


namespace X14_12 {


int ThrowVersusReturn(int value, bool _throw) {
    if (_throw) {
        throw value;
    }
    return value;
}


}  // namespace X14_12


int main() {
    auto start_tc {std::chrono::high_resolution_clock::now()};
    int test {X14_12::ThrowVersusReturn(1, false)};
    auto end_tc {std::chrono::high_resolution_clock::now()};
    std::cout << "int value " << test << " returned in: " <<
            std::chrono::duration_cast<std::chrono::microseconds>(
                end_tc - start_tc).count() << " microsec" << std::endl;
    try {
        start_tc = std::chrono::high_resolution_clock::now();
        X14_12::ThrowVersusReturn(1, true);
    } catch (const int &e) {
        end_tc = std::chrono::high_resolution_clock::now();
        std::cout << "int value " << e << " thrown in: " <<
            std::chrono::duration_cast<std::chrono::microseconds>(
                end_tc - start_tc).count() << " microsec" << std::endl;
    }
}
