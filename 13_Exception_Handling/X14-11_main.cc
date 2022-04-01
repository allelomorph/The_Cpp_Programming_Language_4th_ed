#include <iostream>
#include <sstream>
#include <chrono>


namespace X14_11 {


void ThrowExceptionInCallStack(const unsigned int frame_limit,
                               unsigned int frame_i, unsigned int throw_i) {
    if (frame_i == throw_i) {
        std::stringstream ss;
        ss << "Example throw in recursion frame " << frame_i + 1 <<
            " of " << frame_limit;
        throw std::runtime_error(ss.str());
    }
    if (frame_i < frame_limit)
        ThrowExceptionInCallStack(frame_limit, ++frame_i, throw_i);
}


}  // namespace X14_11


int main() {
    auto start_tc {std::chrono::high_resolution_clock::now()};
    auto end_tc {std::chrono::high_resolution_clock::now()};
    try {
        start_tc = std::chrono::high_resolution_clock::now();
        throw std::runtime_error("Example throw in same function");
    } catch (const std::exception &e) {
        end_tc = std::chrono::high_resolution_clock::now();
        std::cout << e.what() << " caught in: " <<
            std::chrono::duration_cast<std::chrono::microseconds>(
                end_tc - start_tc).count() << " microsec" << std::endl;
    }

    constexpr unsigned int frame_limit {10};
    for (unsigned int i {0}; i < frame_limit; ++i) {
        try {
            start_tc = std::chrono::high_resolution_clock::now();
            X14_11::ThrowExceptionInCallStack(frame_limit, 0, i);
        } catch (const std::exception &e) {
            end_tc = std::chrono::high_resolution_clock::now();
            std::cout << e.what() << " caught in: " <<
                std::chrono::duration_cast<std::chrono::microseconds>(
                    end_tc - start_tc).count() << " microsec" << std::endl;
        }
    }
}
