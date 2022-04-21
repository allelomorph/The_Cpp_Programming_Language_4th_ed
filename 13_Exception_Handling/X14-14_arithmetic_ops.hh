#ifndef X14_14_ARITHMETIC_OPS_HH
#define X14_14_ARITHMETIC_OPS_HH


#include <type_traits>  // is_arithmetic, is_integral, is_signed
#include <limits>       // max, min
#include <stdexcept>    // overflow_error, underflow_error
#include <cmath>        // abs


namespace X14_14 {


// Over/underflow for floating point types is defined differently than for
//   integral types. In that case over/underflow is gradual, where the result is
//   mostly correct but precision is lost, or abrupt, where overflow results in
//   +/- infinity, and underflow results in 0, see:
//   - https://stackoverflow.com/a/40085228
//   - https://journals.sagepub.com/doi/pdf/10.1177/1536867X0800800207
// Currently only testing for abrupt floating point over/underflow, as it is
//   easier to detect.

// For further research into IEEE floating point types, see:
//   - https://cboard.cprogramming.com/c-programming/178245-floating-point-underflow.html
//   - https://www.cplusplus.com/forum/beginner/211790/
//   - https://stackoverflow.com/questions/15675091/how-to-detect-floating-point-underflow-in-c
//   - https://www.youtube.com/watch?v=PZRI1IfStY0
//   - https://www.youtube.com/watch?v=cleObtvThc0&list=PL0oekSefhQVJdk0hSRu6sZ2teWM740NtL&index=12


template <typename T>
T plus(const T &a, const T &b) {
    static_assert(std::is_arithmetic<T>::value,
                  "`plus()` only operates on arithmetic types");
    if (std::is_integral<T>::value) {
        if ((std::is_unsigned<T>::value || (a > 0 && b > 0))
            && b > std::numeric_limits<T>::max() - a)
            throw std::overflow_error("Result greater than data type maximum");
        if (a < 0 && b < 0 && b < std::numeric_limits<T>::min() - a)
            throw std::underflow_error("Result less than data type minimum");
    } else {
        // Overflow may be implementation-dependent result of inf or max
        if (std::abs(a) != std::numeric_limits<T>::infinity() &&
            std::abs(b) != std::numeric_limits<T>::infinity() &&
            std::abs(a + b) == std::numeric_limits<T>::infinity())
            throw std::overflow_error(
                "Absolute value of result greater than data type maximum");
        if (std::abs(a) != std::abs(b) && a + b == 0)
            throw std::underflow_error(
                "Absolute value of result less than data type minimum");
    }
    return a + b;
}


template <typename T>
T minus(const T &a, const T &b) {
    static_assert(std::is_arithmetic<T>::value,
                  "`minus()` only operates on arithmetic types");
    if (std::is_integral<T>::value) {
        if (std::is_signed<T>::value) {
            // b == <T>::min() edge case comes from negating b in test
            if (a > 0 &&
                (b == std::numeric_limits<T>::min() ||
                 (b < 0 && -b > std::numeric_limits<T>::max() - a)))
                throw std::overflow_error("Result greater than data type maximum");
            if (a < 0 && b > 0 && -b < std::numeric_limits<T>::min() - a)
                throw std::underflow_error("Result less than data type minimum");
        }
    } else {
        if (std::abs(a) != std::numeric_limits<T>::infinity() &&
            std::abs(b) != std::numeric_limits<T>::infinity() &&
            std::abs(a - b) == std::numeric_limits<T>::infinity())
            throw std::overflow_error(
                "Absolute value of result greater than data type maximum");
        if (a != b && a - b == 0)
            throw std::underflow_error(
                "Absolute value of result less than data type minimum");
    }
    return a - b;
}


template <typename T>
T multiply(const T &a, const T &b) {
    static_assert(std::is_arithmetic<T>::value,
                  "`multiply()` only operates on arithmetic types");
    if (std::is_integral<T>::value) {
        if (std::is_signed<T>::value) {
            // Signed integral min / or * -1 overflows to max + 1 in two's
            //   complement implementations, see:
            //   - https://stackoverflow.com/q/30394086
            if ((a < 0 && b == std::numeric_limits<T>::min()) ||
                    (a == std::numeric_limits<T>::min() && b < 0))
                throw std::overflow_error("Result greater than data type maximum");
            if ((a > 1 && b > 0 && b > std::numeric_limits<T>::max() / a) ||
                (a < -1 && b < 0 && -b > std::numeric_limits<T>::max() / -a))
                throw std::overflow_error("Result greater than data type maximum");
            if ((a < -1 && b > 0 && b > std::numeric_limits<T>::min() / a) ||
                (a > 1 && b < 0 && -b > std::numeric_limits<T>::min() / -a))
                throw std::underflow_error("Result less than data type minimum");
        } else if (a >= 1 && b > std::numeric_limits<T>::max() / a) {
            throw std::overflow_error("Result greater than data type maximum");
        }
    } else {
        if (std::abs(a) != std::numeric_limits<T>::infinity() &&
            std::abs(b) != std::numeric_limits<T>::infinity() &&
            std::abs(a * b) == std::numeric_limits<T>::infinity())
            throw std::overflow_error(
                "Absolute value of result greater than data type maximum");
        if (a != 0 && b != 0 && a * b == 0)
            throw std::underflow_error(
                "Absolute value of result less than data type minimum");
    }
    return a * b;
}


template <typename T>
T divide(const T &a, const T &b) {
    static_assert(std::is_arithmetic<T>::value,
                  "`divide()` only operates on arithmetic types");
    // Division by 0 is handled at hardware level, which will tell OS (Ubuntu
    //   Linux in this case) to kill process with SIGFPE
    if (std::is_integral<T>::value) {
        if (std::is_signed<T>::value) {
            if ((a == -1 && b == std::numeric_limits<T>::min()) ||
                (a == std::numeric_limits<T>::min() && b == -1))
                throw std::overflow_error("Result greater than data type maximum");
        }
    } else {
        if (std::abs(a) != std::numeric_limits<T>::infinity() &&
            std::abs(b) != std::numeric_limits<T>::infinity() &&
            std::abs(a / b) == std::numeric_limits<T>::infinity())
            throw std::overflow_error(
                "Absolute value of result greater than data type maximum");
        if (a != 0 && a / b == 0)
            throw std::underflow_error(
                "Absolute value of result less than data type minimum");
    }
    return a / b;
}


}  // namespace X14_14


#endif  // X14_14_ARITHMETIC_OPS_HH
