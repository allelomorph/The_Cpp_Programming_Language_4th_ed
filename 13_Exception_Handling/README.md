# X.14 Exception Handling

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (logorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D3) Write a `Checked_ptr<T>` that uses exceptions to signal run-time errors for a pointer supposed to point to an element of an array (or one-beyond-the-end-of the array).\
\
File(s): [`_`](./)

### \[2\]
(D3) Write a function that searches a binary tree of nodes based on a `char*` field for a match. If a node containing `hello` is found, `find("hello")` will return a pointer to that node. Use an exception to indicate "not found."\
\
File(s): [`_`](./)

### \[3\]
(D3) Define a class `Int` that acts exactly like the built-in type `int`, except that it throws exceptions rather than overflowing or underflowing.\
\
File(s): [`_`](./)

### \[4\]
(D2.5) Take the basic operations for opening, closing, reading, and writing from the C interface to your operating system and provide equivalent C++ functions that call the C functions but throw exceptions in case of errors.\
\
File(s): [`_`](./)

### \[5\]
(D2.5) Write a complete `Vector` template with `Range` and `Size` exceptions.\
\
File(s): [`_`](./)

### \[6\]
(D1) Write a loop that computes the sum of a `Vector` as defined in §X.14\[5\] without examining the size of the `Vector`. Why is this a bad idea?\
\
File(s): [`_`](./)

### \[7\]
(D2.5) Consider using a class `Exception` as the base of all classes used as exceptions. What should it look like? How should it be used? What good might it do? What disadvantages might result from a requirement to use such a class?\
\
File(s): [`_`](./)

### \[8\]
(D1) Given:
```C++
int main() { /* ... */ }
```
Change it so that it catches all exceptions thrown from the ..., turns them into error messages, and `abort()`s.\
\
File(s): [`_`](./)

### \[9\]
(D2) Write a class or template suitable for implementing callbacks.\
\
File(s): [`_`](./)

### \[10\]
(D2) Write a program consisting of functions calling each other to a calling depth of 10. Give each function an argument that determines at which level an exception is thrown. Have
`main()` catch these exceptions and print out which exception is caught. Don’t forget the case in which an exception is caught in the function that throws it.\
\
File(s): [`_`](./)

### \[11\]
(D2) Modify the program from §X.14[10] to measure if there is a difference in the cost of catching exceptions depending on where in the function call stack the exception is thrown. Add a string object to each function and measure again.\
\
File(s): [`_`](./)

### \[12\]
(D2) Write a function that either returns a value or that throws that value based on an argument. Measure the difference in run-time between the two ways.\
\
File(s): [`_`](./)

### \[13\]
(D2) Modify the calculator version from §X.15[2] to use exceptions. Keep a record of the mistakes you make. Suggest ways of avoiding such mistakes in the future.\
\
File(s): [`_`](./)

### \[14\]
(D2.5) Write `plus()`, `minus()`, `multiply()`, and `divide()` functions that check for possible overflow and underflow and that throw exceptions if such errors happen.\
\
File(s): [`_`](./)

### \[15\]
(D2) Modify the calculator to use the functions from §X.14\[14\].\
\
File(s): [`_`](./)
