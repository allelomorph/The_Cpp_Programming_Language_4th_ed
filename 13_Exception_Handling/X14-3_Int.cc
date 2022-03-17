#include "X14-2_Int.hh"
#include <iostream>


namespace X14_2 {


// Templated member functions are most easily handled by including the
//   defintiion in the header rather than the .cpp/.cc file, see:
//   - https://stackoverflow.com/q/972152/
// template <typename T>
// void Int::check_lvref(const T &v) {


std::ostream &operator<<(std::ostream &os, const Int &i) {
    return os << i.n;
}


std::istream &operator>>(std::ostream &is, const Int &i) {
    return is >> i.n;
}


}  // namespace X14_2
