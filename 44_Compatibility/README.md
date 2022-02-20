# X.45 Compatibility

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (logorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D2.5) Take a C program and convert it to a C++ program; list the kinds of non-C++ constructs used and determine if they are valid ANSI C constructs. First convert the program to strict ANSI C (adding prototypes, etc.), then to C++. Estimate the time it would take to convert a 100,000 line C program to C++.\
\
File(s): [`_`](./)

### \[2\]
(D2) Without looking in the book, write down as many C++ keywords as you can.\
\
File(s): [`_`](./)

### \[3\]
(D2) Write a standards-conforming C++ program containing a sequence of at least ten different consecutive keywords not separated by identifiers, operators, punctuation characters, etc.\
\
File(s): [`_`](./)

### \[4\]
(D2.5) Write a program to help convert C programs to C++ by renaming variables that are C++ keywords, replacing calls of `malloc()` by uses of `new`, etc. Hint: don’t try to do a perfect job.\
\
File(s): [`_`](./)

### \[5\]
(D2) Replace all uses of `malloc()` in a C-style C++ program (maybe a recently converted C program) to uses of `new`.\
\
File(s): [`_`](./)

### \[6\]
(D2.5) Minimize the use of macros, global variables, uninitialized variables, and casts in a C-style C++ program (maybe a recently converted C program).\
\
File(s): [`_`](./)

### \[7\]
(D3) Take a C++ program that is the result of a crude conversion from C and critique it as a C++ program considering locality of information, abstraction, readability, extensibility, and potential for reuse of parts. Make one significant change to the program based on that critique.\
\
File(s): [`_`](./)

### \[8\]
(D2) Take a small (say, 500 line) C++ program and convert it to C. Compare the original with the result for size and probable maintainability.\
\
File(s): [`_`](./)

### \[9\]
(D3) Write a small set of test programs to determine whether a C++ implementation has "the latest" standard features. Checking for keywords is easy. For example, is `constexpr` recognized? Are delegating constructors supported? Can you inherit constructors?\
\
File(s): [`_`](./)

### \[10|]
(D2.5) Take a C++ program that use `<X.h>` headers and convert it to using `<X>` and `<cX>` headers. Minimize the use of using-directives.\
\
File(s): [`_`](./)
