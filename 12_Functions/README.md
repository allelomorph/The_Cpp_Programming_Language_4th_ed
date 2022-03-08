# X.13 Functions

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (logorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D1) Write declarations for the following: a function taking arguments of type pointer to character and reference to integer and returning no value; a pointer to such a function; a function taking such a pointer as an argument; and a function returning such a pointer. Write the definition of a function that takes such a pointer as an argument and returns its argument as the return value. Hint: Use a type alias (`using`).\
\
File(s): [`X13-1_main.cc`](./X13-1_main.cc)\
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X13-1_main.cc`

### \[2\]
(D1) What does the following mean? What would it be good for?
```C++
using riffi = int (&) (int, int);
```
\
File(s): [`_`](./)

### \[3\]
(D1.5) Write a program like "Hello, world!" that takes a name as a command-line argument and writes "Hello, *name* !". Modify this program to take any number of names as arguments and to say hello to each.\
\
File(s): [`_`](./)

### \[4\]
(D1.5) Write a program that reads an arbitrary number (possibly limited to some maximum number) of files whose names are given as command-line arguments and writes them one after another on `cout`. Because this program concatenates its arguments to produce its output, you might call it `cat`.\
\
File(s): [`_`](./)

### \[5\]
(D2) Convert a small C program to C++. Modify the header files to declare all functions called and to declare the type of every argument. Where possible, replace #defines with enum, const, constexpr, or inline. Remove extern declarations from .cpp files and if necessary convert all function definitions to C++ function definition syntax. Replace calls of `malloc()` and `free()` with new and delete. Remove unnecessary casts.\
\
File(s): [`_`](./)

### \[6\]
(D2) Modify the result of §X.13\[5\] by eliminating arrays and "naked" `new`s and `delete`s. Hint: vector and array.\
\
File(s): [`_`](./)

### \[7\]
(D2) Implement `ssort()` (§12.5) using a more efficient sorting algorithm. Hint: `sort()` and `qsort()`.\
\
File(s): [`_`](./)

### \[8\]
(D2.5) Consider:
```C++
struct Tnode {
    string word;
    int count;
    Tnode* left;
    Tnode* right;
};
```
Write a function for entering new words into a tree of `Tnode`s. Write a function to write out a tree of `Tnode`s. Write a function to write out a tree of `Tnode`s with the words in alphabetical order. Modify `Tnode` so that it stores (only) a pointer to an arbitrarily long word stored as an array of characters on free store using new. Modify the functions to use the new definition of `Tnode`.\
\
File(s): [`_`](./)

### \[9\]
(D2.5) Write a function to invert a two-dimensional array. Hint: §7.4.2.\
\
File(s): [`_`](./)

### \[10\]
(D2) Write an encryption program that reads from `cin` and writes the encoded characters to `cout`. You might use this simple encryption scheme: the encrypted form of a character `c` is `cˆkey[i]`, where `key` is a string passed as a command-line argument. The program uses the characters in `key` in a cyclic manner until all the input has been read. Re-encrypting encoded text with the same key produces the original text. If no key (or a null string) is passed, then no encryption is done.\
\
File(s): [`_`](./)

### \[11\]
(D3.5) Write a program to help decipher messages encrypted with the method described in §X.13\[9\] without knowing the key. Hint: See David Kahn: *The Codebreakers*, Macmillan, 1967, New York, pp. 207-213.\
\
File(s): [`_`](./)

### \[12\]
(D2) Without using copy and paste, implement and test TEA (the Tiny Encryption Algorithm). D.J. Wheeler and R.M. Needham: *TEA, a tiny encryption algorithm*. Lecture Notes in Computer Science 1008: 363366. http://143.53.36.235:8080/tea.htm.
\
\
File(s): [`_`](./)

### \[13\]
(D1) How would you choose names for pointer to function types defined using a type alias?\
\
File(s): [`_`](./)

### \[14\]
(D2) Look at some programs to get an idea of the diversity of styles of names actually used. How are uppercase letters used? How is the underscore used? When are short names such as `i` and `x` used?\
\
File(s): [`_`](./)

### \[15\]
(D1) What is wrong with these macro definitions?
```C++
#define PI = 3.141593;
#define MAX(a,b) a>b?a:b
#define fac(a) (a)*fac((a)−1)
```
\
File(s): [`_`](./)

### \[16\]
(D3) Write a macro processor that defines and expands simple macros (like the C preprocessor does). Read from `cin` and write to `cout`. At first, don’t try to handle macros with arguments. Hint: The desk calculator (§10.2) contains a symbol table and a lexical analyzer that you could modify.\
\
File(s): [`_`](./)

### \[17\]
(D3) Write an `error` function that takes a `printf`-style format string containing `%s`, `%c`, and `%d` directives and an arbitrary number of arguments. Don’t use `printf()`. Look at §43.3 if you don’t know the meaning of `%s`, `%c`, and `%d`. Use `<cstdarg>`.\
\
File(s): [`_`](./)

### \[18\]
(D2) Implement a useful subset of `print()` from §12.2.5.\
\
File(s): [`_`](./)

### \[19\]
(D2) Add functions such as `sqrt()`, `log()`, and `sin()` to the desk calculator from §10.2. Hint: Predefine the names and call the functions through an array of pointers to functions. Don’t forget to check the arguments in a function call.\
\
File(s): [`_`](./)

### \[20\]
(D1) Write a factorial function that does not use recursion.\
\
File(s): [`_`](./)

### \[21\]
(D2) Write functions to add one day, one month, and one year to a `Date` as defined in §X.9\[4\]. Write a function that gives the day of the week for a given `Date`. Write a function that gives the `Date` of the first Monday following a given `Date`.\
\
File(s): [`_`](./)
