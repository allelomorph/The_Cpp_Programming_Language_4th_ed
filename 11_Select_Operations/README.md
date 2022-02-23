# X.12 Select Operations

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (logorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D1) Copy all even non-zero elements of an `int[]` into a `vector<int>`. Use a pointer and `++` for the traversal.\
\
File(s): [`X12-1_main.cc`](./X12-1_main.cc)\
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X12-1_main.cc`

### \[2\]
(D2) Allocate so much memory using `new` that `bad_alloc` is thrown. Report how much memory was allocated and how much time it took. Do this twice: once not writing to the allocated memory and once writing to each element.\
\
File(s): [`_`](./)

### \[3\]
Write a simple loop calculating a sum of elements (like `std::accumulate()`). Write it in a dozen or more ways using `for`-statements, range-`for` statements, the `for_each()` algorithm, using indices, pointers, and iterators, using "plain code", function objects, and lambdas, and using different element types. See if you can find any performance differences between the different versions.\
\
File(s): [`_`](./)

### \[4\]
(D2.5) Define an `apply(v,f)` that applies a function `f` to each element of `v` assumed to be a `vector<Shape*>`. Test `apply()` with a a variety of functions, function objects, and lambdas. Note that by capturing variables from a lambda or storing values in a function object, you can call Shape functions that takes arguments without having to have `f()` take explicit arguments. Hint: there is a variety of ways of specifying `apply()`'s argument types; experiment.\
\
File(s): [`_`](./)

### \[5\]
(D4) Find a program of a few thousand lines of code, preferably a program used for a real-world task, rather than an exercise solution. Count the number of casts (of all kinds). If not already done, classify all casts by turning them into named casts. Eliminate as many `static_casts`, `reinterpret_casts`, and `const_casts` as possible. This will most likely involve adding specific type conversion functions, templates, etc.\
\
File(s): [`_`](./)
