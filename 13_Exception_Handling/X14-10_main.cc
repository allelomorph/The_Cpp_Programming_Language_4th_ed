#include <iostream>
#include <sstream>


namespace X14_10 {


void ThrowExceptionInCallStack(const unsigned int frame_limit,
                               unsigned int frame_i, unsigned int throw_i) {
    if (frame_i == throw_i) {
        std::stringstream ss;
        ss << "Example throw in recursion frame: " << frame_i + 1 <<
            " of " << frame_limit;
        throw std::runtime_error(ss.str());
    }
    if (frame_i < frame_limit)
        ThrowExceptionInCallStack(frame_limit, ++frame_i, throw_i);
}


}  // namespace X14_10


int main() {
    try {
        throw std::runtime_error("Example throw in same function");
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    constexpr unsigned int frame_limit {10};
    for (unsigned int i {0}; i < frame_limit; ++i) {
        try {
            X14_10::ThrowExceptionInCallStack(frame_limit, 0, i);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}
