#include <iostream>
#include <system_error>
#include <string>

#include <sys/stat.h>    // open(2)
#include <sys/types.h>   // open(2), lseek(2)
#include <fcntl.h>       // open(2)
#include <unistd.h>      // close (2), write(2), read(2), lseek(2), unlink(2)


namespace X14_4 {


int SafeC_open(const char *pathname, int flags, mode_t mode) {
    int fd {open(pathname, flags, mode)};
    if (fd == -1) {
        std::system_error se (errno, std::generic_category(), "SafeC_open");
        errno = 0;
        throw se;
    }
    return fd;
}


void SafeC_close(int fd) {
    int retval {close(fd)};
    if (retval == -1) {
        std::system_error se (errno, std::generic_category(), "SafeC_close");
        errno = 0;
        throw se;
    }
}


ssize_t SafeC_write(int fd, const void *buf, size_t count) {
    ssize_t retval {write(fd, buf, count)};
    if (retval == -1) {
        std::system_error se (errno, std::generic_category(), "SafeC_write");
        errno = 0;
        throw se;
    }
    return retval;
}


ssize_t SafeC_read(int fd, void *buf, size_t count) {
    ssize_t retval {read(fd, buf, count)};
    if (retval == -1) {
        std::system_error se (errno, std::generic_category(), "SafeC_read");
        errno = 0;
        throw se;
    }
    return retval;
}


}  // namespace X14_4


int main() {
    try {
        X14_4::SafeC_open("blah", 0, 0);
    } catch (const std::system_error &se) {
        std::cout << se.what() << '\n';
    }
    try {
        X14_4::SafeC_close(-1);
    } catch (const std::system_error &se) {
        std::cout << se.what() << '\n';
    }
    try {
        X14_4::SafeC_write(-1, nullptr, 0);
    } catch (const std::system_error &se) {
        std::cout << se.what() << '\n';
    }
    try {
        X14_4::SafeC_read(-1, nullptr, 0);
    } catch (const std::system_error &se) {
        std::cout << se.what() << '\n';
    }

    const std::string filename {"X14-4_test.txt"};
    const std::string wbuf {"X14-4_test X14-4_test X14-4_test"};
    char rbuf[100] {0};
    int fd {X14_4::SafeC_open(filename.c_str(), O_RDWR | O_CREAT | O_TRUNC,
                              S_IRUSR | S_IWUSR)};
    X14_4::SafeC_write(fd, wbuf.c_str(), wbuf.size());
    lseek(fd, 0, SEEK_SET);  // return offset to start of file
    X14_4::SafeC_read(fd, rbuf, wbuf.size());
    std::cout << filename << " contents:" << std::endl <<
        rbuf << std::endl;
    X14_4::SafeC_close(fd);
    unlink(filename.c_str());  // delete test file
}
