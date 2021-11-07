# X.8 Pointers, Arrays, and References

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (algorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D1) Write declarations for the following: a pointer to a character, an array of 10 integers, a reference to an array of 10 integers, a pointer to an array of character strings, a pointer to a pointer to a character, a constant integer, a pointer to a constant integer, and a constant pointer to an integer. Initialize each one.\
\
File(s): [`_`](./)

### \[2\]
(D1.5) What, on your system, are the restrictions on the pointer types `char*`, `int*`, and `void*`? For example, may an `int*` have an odd value? Hint: alignment.\
\
File(s): [`_`](./)

### \[3\]
(D1) Use an alias (`using`) to define the types `unsigned char`, `const unsigned char`, pointer to integer, pointer to pointer to `char`, pointer to array of `char`, array of 7 pointers to `int`, pointer to an array of 7 pointers to `int`, and array of 8 arrays of 7 pointers to `int`.\
\
File(s): [`_`](./)

### \[4\]
(D1) Given two `char*`s pointing into an array, find and output the number of characters between the two pointed-to characters (zero if they point to the same element).\
\
File(s): [`_`](./)

### \[5\]
(D1) Given two `int*`s pointing into an array, find and output the number of `int`s between the
two pointed-to `int`s (zero if they point to the same element).\
\
File(s): [`_`](./)

### \[6\]
(D2) What happens when you read and write beyond the bounds of an array. Do a few experiments involving a global array of `ints`, a local array of `int`s, an array of `int`s allocated by `new`, and a member array of `int`s. Try reading and writing just beyond the end and far beyond the end. Try the same for just before and far before the beginning. See what happens for different optimizer levels. Then try hard never to do out-of-range access by mistake.\
\
File(s): [`_`](./)

### \[7\]
(D1) Write a function that swaps (exchanges the values of) two integers. Use `int*` as the argument type. Write another swap function using `int&` as the argument type.\
\
File(s): [`_`](./)

### \[8\]
(D1.5) What is the size of the array `str` in the following example:
```C++
char str[] = "a short string";
```
What is the length of the string `"a short string"`?\
\
File(s): [`_`](./)

### \[9\]
(D1) Define functions `f(char)`, `g(char&)`, and `h(const char&)`. Call them with the arguments `'a'`, `49`, `3300`, `c`, `uc`, and `sc`, where `c` is a `char`, `uc` is an `unsigned char`, and `sc` is a `signed char`. Which calls are legal? Which calls cause the compiler to introduce a temporary variable?\
\
File(s): [`_`](./)

### \[10\]
(D1) Define an array of strings in which the strings contain the names of the months. Print those strings. Pass the array to a function that prints those strings.\
\
File(s): [`_`](./)

### \[11\]
(D2) Read a sequence of words from input. Use `Quit` as a word that terminates the input. Print the words in the order they were entered. Don’t print a word twice. Modify the program to sort the words before printing them.\
\
File(s): [`_`](./)

### \[12\]
(D2) Write a function that counts the number of occurrences of a pair of letters in a `string` and another that does the same in a zero-terminated array of `char` (a C-style string). For example, the pair `"ab"` appears twice in `"xabaacbaxabb"`.\
\
File(s): [`_`](./)

### \[13\]
(D2) Run some tests to see if your compiler really generates equivalent code for iteration using pointers and iteration using indexing (§7.4.1). If different degrees of optimization can be requested, see if and how that affects the quality of the generated code.\
\
File(s): [`_`](./)
