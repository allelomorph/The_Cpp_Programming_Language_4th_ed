# X.19 Overloading

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (logorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D2) In the following program, which conversions are used in each expression?
```C++
struct X {
    int i;
    X(int);
    X operator+(int);
};

struct Y {
    int i;
    Y(X);
    Y operator+(X);
    operator int();
};

extern X operatorD(X, Y);
extern int f(X);

X x = 1;
Y y = x;
int i = 2;

int main()
{
    i + 10;
    y + 10;
    y + 10 * y;

    x + y + i;
    x * x + i;

    f(7);
    f(y);

    y + y;
    106 + y;
}
```
Modify the program so that it will run and print the values of each legal expression.\
\
File(s): [`_`](./)

### \[2\]
(D2) Complete and test class `String` from §19.3.\
\
File(s): [`_`](./)

### \[3\]
(D2) Define a class `INT` that behaves exactly like an `int`. Hint: Define `INT::operator int()`.\
\
File(s): [`_`](./)

### \[4\]
(D1) Define a class `RINT` that behaves like an `int` except that the only operations allowed are `+` (unary and binary), `−` (unary and binary), `*`, `/`, and `%`. Hint: Do not define `RINT::operator int()`.\
\
File(s): [`_`](./)

### \[5\]
(D3) Define a class `LINT` that behaves like a `RINT`, except that it has at least 64 bits of precision.\
\
File(s): [`_`](./)

### \[6\]
(D4) Define a class implementing arbitrary precision arithmetic. Test it by calculating the factorial of `1000`. Hint: You will need to manage storage in a way similar to what was done for class `String`.\
\
File(s): [`_`](./)

### \[7\]
(D2) Write a program that has been rendered unreadable through use of operator overloading and macros. An idea: Define `+` to mean `−` and vice versa for `INT`s. Then, use a macro to define `int` to mean `INT.` Redefine popular functions using reference type arguments. Writing a few misleading comments can also create great confusion\
\
File(s): [`_`](./)

### \[8\]
(D3) Swap the result of §X.19\[7\] with a friend. Without running it, figure out what your friend’s program does. When you have completed this exercise, you’ll know what to avoid.\
\
File(s): [`_`](./)

### \[9\]
(D2) Define a type `Vec4` as a vector of four `floats`. Define `operator[]` for `Vec4`. Define operators `+`, `−`, `*`, `/`, `=`, `+=`, `−=`, `*=`, and `/=` for combinations of vectors and floating-point numbers.\
\
File(s): [`_`](./)

### \[10\]
(D3) Define a class `Mat4` as a vector of four `Vec4`s. Define `operator[]` to return a `Vec4` for `Mat4`. Define the usual matrix operations for this type. Define a function doing Gaussian elimination for a `Mat4`.\
\
File(s): [`_`](./)

### \[11\]
(D2) Define a class `Vector` similar to `Vec4` but with the size given as an argument to the constructor `Vector::Vector(int)`.\
\
File(s): [`_`](./)

### \[12\]
(D3) Define a class `Matrix` similar to `Mat4` but with the dimensions given as arguments to the constructor `Matrix::Matrix(int,int)`.\
\
File(s): [`_`](./)

### \[13\]
(D1) Given two structures:
```C++
struct S { int x, y; };
struct T { char* p; char* q; };
```
write a class `C` that allows the use of `x` and `p` from some `S` and `T`, much as if `x` and `p` had been members of `C`. Hint: pointer to member.\
\
File(s): [`_`](./)

### \[14\]
(D1.5) Define a class Index to hold the index for an exponentiation function `mypow(double,Index)`. Find a way to have `2**I` call `mypow(2,I)`.\
\
File(s): [`_`](./)

### \[15\]
(D2) Define a class `Imaginary` to represent imaginary numbers. Define class `Complex` based on that. Implement the fundamental arithmetic operators. Define `i` as a user-defined literal suffix meaning "imaginary."\
\
File(s): [`_`](./)
