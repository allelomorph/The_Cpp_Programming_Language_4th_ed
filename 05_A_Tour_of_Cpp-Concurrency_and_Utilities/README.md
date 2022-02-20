# X.6 A Tour of C++: Concurrency and Utilities

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (logorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
When first reading this chapter, keep a record of information that was new or surprising to you. Later, use that list to focus your further studies.

### \[2\]
(D1.5) Write a program with two `thread`s: one that writes `hello` every second and one that writes `world!` every second.\
\
File(s): [`X6-2_main.cc`](./X6-2_main.cc) [`X6-2_TSafePrintPerSec.hh`](./X6-2_TSafePrintPerSec.hh)\
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 -pthread X6-2_main.cc`

### \[3\]
(D2) Time a loop. Write out the time in milliseconds. Do this for the default setting of your compiler and for a setting using an optimizer (e.g., `−O2` or "release"). Be careful not to have the optimizer eliminate your whole loop as dead code because you did not use a result.\
\
File(s): [`X6-3_main.cc`](./X6-3_main.cc)\
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 -pthread X6-3_main.cc`

### \[4\]
(D2) Repeat the histogram drawing example from §5.6.3 for a normal_distribution and 30 rows.\
\
File(s): [`X6-4_main.cc`](./X6-4_main.cc)\
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X6-4_main.cc`

### \[5\]
(D1.5) Use a `regex` to find all decimal numbers in a file.\
\
File(s): [`X6-5_main.cc`](./X6-5_main.cc) [`X6-5_UniformRandIntGen.hh`](./X6-5_UniformRandIntGen.hh)\
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X6-5_main.cc`
