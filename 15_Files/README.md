# X.16 Files

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (logorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D2) Find where the standard library headers are kept on your system. List their names. Are any nonstandard headers kept together with the standard ones? Can any nonstandard headers be `#include`d using the `<>` notation?\
\
File(s): [`_`](./)

### \[2\]
(D2) Where are the headers for nonstandard "foundation" libraries kept?\
\
File(s): [`_`](./)

### \[3\]
(D2.5) Write a program that reads a source file and writes out the names of files `#include`d. Indent file names to show files `#include`d by included files. Try this program on some real source files (to get an idea of the amount of information included).\
\
File(s): [`_`](./)

### \[4\]
(D3) Modify the program from the previous exercise to print the number of comment lines, the number of non-comment lines, and the number of non-comment, whitespace-separated words for each file `#include`d.\
\
File(s): [`_`](./)

### \[5\]
(D2.5) An external include guard is a construct that tests outside the file it is guarding and `include`s only once per compilation. Define such a construct, devise a way of testing it, and discuss its advantages and disadvantages compared to the include guards described in §15.3.3. Is there any significant run-time advantage to external include guards on your system?\
\
File(s): [`_`](./)

### \[6\]
(D3) How is dynamic linking achieved on your system? What restrictions are placed on dynamically linked code? What requirements are placed on code for it to be dynamically linked?\
\
File(s): [`_`](./)

### \[7\]
(D3) Open and read 100 files containing 1500 characters each. Open and read one file containing 150,000 characters. Is there a performance difference? What is the highest number of files that can be simultaneously open on your system? Consider these questions in relation to the use of `#include` files.\
\
File(s): [`_`](./)

### \[8\]
(D2) Modify the desk calculator so that it can be invoked from `main()` or from other functions as a simple function call.\
\
File(s): [`_`](./)

### \[9\]
(D2) Draw the "module dependency diagrams" (§15.3.2) for the version of the calculator that used `error()` instead of exceptions (§14.2.2).\
\
File(s): [`_`](./)
