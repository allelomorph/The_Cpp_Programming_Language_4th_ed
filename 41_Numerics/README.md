# X.41 Numerics

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (algorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D1.5) Write a function that behaves like `apply()` from §40.5.3, except that it is a nonmember function and accepts function objects.\
\
File(s): [`_`](./)

### \[2\]
(D1.5) Write a function that behaves like `apply()` from §40.5.3, except that it is a nonmember function, accepts function objects, and modifies its `valarray` argument.\
\
File(s): [`_`](./)

### \[3\]
(D2) Complete `Slice_iter` (§40.5.4). Take special care when defining the destructor.\
\
File(s): [`_`](./)

### \[4\]
(D1.5) Rewrite the functions in §29.3.3 using `accumulate()`.\
\
File(s): [`_`](./)

### \[5\]
(D2) Implement I/O operators `<<` and `>>` for `valarray`. Implement a `get_array()` function that creates a valarray of a size specified as part of the input itself.\
\
File(s): [`_`](./)

### \[6\]
(D2.5) Define and implement a three-dimensional matrix with suitable operations.\
\
File(s): [`_`](./)

### \[7\]
(D2.5) Define and implement an n−dimensional matrix with suitable operations.\
\
File(s): [`_`](./)

### \[8\]
(D2.5) Implement a `valarray`-like class and implement `+` and Dfor it. Compare its performance to the performance of your C++ implementation’s `valarray`. Hint: Include `x=0.5(x+y)+z` among your test cases and try it with a variety of sizes for the vectors `x`, `y`, and `z`.\
\
File(s): [`_`](./)

### \[9\]
(D3) Implement a Fortran-style array `Fort_array` where indices start from `1` rather than `0`.\
\
File(s): [`_`](./)

### \[10\]
(D3) Implement `Matrix` using a `valarray` member as the representation of the elements (rather than a pointer or a reference to a `valarray`).\
\
File(s): [`_`](./)

### \[11\]
(D2) Generalize the idea from the program in §40.7 into a function that, given a generator as an argument, prints a simple graphical representation of its distribution that can be used as a crude visual check of the generator’s correctness.\
\
File(s): [`_`](./)

### \[12\]
(D1) If `n` is an `int`, what is the distribution of `(double(rand())/RAND_MAX)*n`?\
\
File(s): [`_`](./)

### \[13\]
(D2.5) Plot points in a square output area. The coordinate pairs for the points should be generated by `Urand(N)`, where `N` is the number of pixels on a side of the output area. What does the output tell you about the distribution of numbers generated by `Urand`?\
\
File(s): [`_`](./)

### \[14\]
(D2) Implement a Normal distribution generator, `Nrand`.\
\
File(s): [`_`](./)