#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
#include "UniformRandIntGen.hh"


// Running in development environment (Ubuntu 20.04 VM) always results in the
//   OS ending the process with SIGKILL before std::bad_alloc is thrown.
//   However, no obvious limits are imposed on heap memory in processes, see
//   notes below main().

int main() {
    std::size_t *p;
    std::vector<std::size_t *> vec;
    UniformRandIntGen<std::size_t> rnd(
        0, std::numeric_limits<std::size_t>::max());

    // without writing to pointers
    auto start {
        std::chrono::high_resolution_clock::now()};
    for (bool loop {true}; loop;) {
        try {
            // allocating WORD sized payloads (size_t)
            p = new std::size_t;
            vec.push_back(p);
        } catch (const std::bad_alloc &e) {
            std::cout << "Exception: " << e.what() << " after " <<
                vec.size() << " successful allocations" << std::endl;
            loop = false;
        }
    }
    auto stop {
        std::chrono::high_resolution_clock::now()};
    auto duration {std::chrono::duration_cast<std::chrono::milliseconds>(
            stop - start)};
    std::cout << "Allocation loop took " << duration.count() <<
        " milliseconds" << std::endl;
    // empty vector
    for (auto &x : vec)
        delete x;
    vec.clear();

    // with writing to pointers
    start = std::chrono::high_resolution_clock::now();
    for (bool loop {true}; loop;) {
        try {
            p = new std::size_t;
            *p = rnd();
            vec.push_back(p);
        } catch (const std::bad_alloc &e) {
            std::cout << "Exception: " << e.what() << " after " <<
                vec.size() << " successful allocations" << std::endl;
            loop = false;
        }
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(
        stop - start);
    std::cout << "Allocation loop took " << duration.count() <<
        " milliseconds" << std::endl;

    // empty vector
    for (auto &x : vec)
        delete x;
}


/*
// Current output of `ulimit -a`:
core file size          (blocks, -c) 0
data seg size           (kbytes, -d) unlimited
scheduling priority             (-e) 0
file size               (blocks, -f) unlimited
pending signals                 (-i) 3770
max locked memory       (kbytes, -l) 65536
max memory size         (kbytes, -m) unlimited
open files                      (-n) 1024
pipe size            (512 bytes, -p) 8
POSIX message queues     (bytes, -q) 819200
real-time priority              (-r) 0
stack size              (kbytes, -s) 8192
cpu time               (seconds, -t) unlimited
max user processes              (-u) 3770
virtual memory          (kbytes, -v) unlimited
file locks                      (-x) unlimited

// and contents of /etc/security/limits.conf:
# /etc/security/limits.conf
#
#Each line describes a limit for a user in the form:
#
#<domain>        <type>  <item>  <value>
#
#Where:
#<domain> can be:
#        - a user name
#        - a group name, with @group syntax
#        - the wildcard *, for default entry
#        - the wildcard %, can be also used with %group syntax,
#                 for maxlogin limit
#        - NOTE: group and wildcard limits are not applied to root.
#          To apply a limit to the root user, <domain> must be
#          the literal username root.
#
#<type> can have the two values:
#        - "soft" for enforcing the soft limits
#        - "hard" for enforcing hard limits
#
#<item> can be one of the following:
#        - core - limits the core file size (KB)
#        - data - max data size (KB)
#        - fsize - maximum filesize (KB)
#        - memlock - max locked-in-memory address space (KB)
#        - nofile - max number of open file descriptors
#        - rss - max resident set size (KB)
#        - stack - max stack size (KB)
#        - cpu - max CPU time (MIN)
#        - nproc - max number of processes
#        - as - address space limit (KB)
#        - maxlogins - max number of logins for this user
#        - maxsyslogins - max number of logins on the system
#        - priority - the priority to run user process with
#        - locks - max number of file locks the user can hold
#        - sigpending - max number of pending signals
#        - msgqueue - max memory used by POSIX message queues (bytes)
#        - nice - max nice priority allowed to raise to values: [-20, 19]
#        - rtprio - max realtime priority
#        - chroot - change root to directory (Debian-specific)
#
#<domain>      <type>  <item>         <value>
#

#*               soft    core            0
#root            hard    core            100000
#*               hard    rss             10000
#@student        hard    nproc           20
#@faculty        soft    nproc           20
#@faculty        hard    nproc           50
#ftp             hard    nproc           0
#ftp             -       chroot          /ftp
#@student        -       maxlogins       4

# End of file
*/
