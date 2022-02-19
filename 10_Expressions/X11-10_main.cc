#include <iostream>
#include <algorithm>  // swap
#include <string.h>   // strlen


// Not sure if the task instructions imply avoiding use of STL. C++17 and 20
//   apparently have std::reverse(). Building a mostly C-like solution instead.


namespace X11_10 {


char *rev(char *s) {
    if (s == nullptr)
        throw std::invalid_argument("X11_10::rev: nullptr parameter");

    std::size_t len {strlen(s)};
    for (std::size_t i {0}, j {len - 1}; i <= len / 2; ++i, --j)
        std::swap(s[i], s[j]);
    return s;
}


}  // namespace X11_10



int main() {
    char even_len_str[5] {"1234"};
    char odd_len_str[6] {"12345"};

    std::cout << "rev(\"" << even_len_str << "\"): \"" <<
        X11_10::rev(even_len_str) << '"' << std::endl;
    std::cout << "rev(\"" << odd_len_str << "\"): \"" <<
        X11_10::rev(odd_len_str) << '"' << std::endl;
}
