#include <iostream>
#include <string.h>  // strlen strncpy


// Not sure if the task instructions imply avoiding use of STL <string>. Given
//   most solutions using the STL would be trivial, building a C-like solution
//   instead. Presumably glibc strcat and strncat are also not allowed.


namespace X11_9 {


char *cat(const char *s1, const char *s2) {
    if (s1 == nullptr || s2 == nullptr)
        throw std::invalid_argument("X11_9::cat: nullptr parameter");

    std::size_t len1 {strlen(s1)};
    std::size_t len2 {strlen(s2)};
    char *concat {new char[len1 + len2 + 1]};

    std::cout << "Buffer allocated in cat() @ " <<
        static_cast<void *>(concat) << std::endl;
    strncpy(concat, s1, len1);
    strncpy(concat + len1, s2, len2);
    concat[len1 + len2] = '\0';
    return concat;
}


}  // namespace X11_9



int main() {
    char *concat {X11_9::cat("111test111", "222test222")};
    std::cout << "Buffer returned to main() @ " <<
        static_cast<void *>(concat) << std::endl;
    std::cout << "`cat(\"111test111\", \"222test222\")`: \"" << concat <<
        '"' << std::endl;
}
