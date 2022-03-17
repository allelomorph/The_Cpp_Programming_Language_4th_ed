#ifndef INT_HH
#define INT_HH

#include <iostream>
#include <type_traits>
#include <limits>


namespace X14_2 {


class Int {
public:
    Int() :n{} {}

    template <typename T>
    Int(const T &v) {
        std::cout << "\tInt(lvref)\n";
        try { check_lvref(v); } catch (...) { throw; }
        this->n = v;
    }
    template <typename T>
    Int &operator=(const T &v) {
        std::cout << "\tInt op=(lvref)\n";
        try { check_lvref(v); } catch (...) { throw; }
        this->n = v;
        return *this;
    }
    template <typename T>
    Int(const T &&v) {
        std::cout << "\tInt(rvref)\n";
        try { check_lvref(T {v}); } catch (...) { throw; }
        this->n = v;
    }
    template <typename T>
    Int &operator=(const T &&v) {
        std::cout << "\tInt op=(rvref)\n";
        try { check_lvref(T {v}); } catch (...) { throw; }
        this->n = v;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Int &i);
    friend std::istream &operator>>(std::ostream &is, const Int &i);

private:
    int n;
    template <typename T>
    void check_lvref(const T &v);
};


// Templated member functions are most easily handled by including the
//   defintiion in the header rather than the .cpp/.cc file, see:
//   - https://stackoverflow.com/q/972152/
template <typename T>
void Int::check_lvref(const T &v) {
    if (std::is_arithmetic<T>::value) {
        if (v > std::numeric_limits<int>::max()) {
            throw (std::out_of_range("Instantiating an Int with this value"
                                     " would overflow INT_MAX"));
        }
        if (v < std::numeric_limits<int>::min()) {
            throw (std::out_of_range("Instantiating an Int with this value"
                                     " would underflow INT_MIN"));
        }
    } else {  // compiler will first disallow most incompatible conversions
        throw (std::invalid_argument(
                   "Int can only be instantiated from arithmetic type"));
    }
}


}  // namespace X14_2


#endif  // INT_HH
