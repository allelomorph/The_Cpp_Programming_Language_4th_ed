# X.17 Classes

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (logorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D1) Find the error in `Date::add_year()` in §16.2.3. Then find two additional errors in the version in §16.2.10.\
\
File(s): [`_`](./)

### \[2\]
(D2.5) Complete and test `Date`. Reimplement it with "number of days after 1/1/1970" representation.\
\
File(s): [`_`](./)

### \[3\]
(D2) Find a `Date` class that is in commercial use. Critique the facilities it offers. If possible, then discuss that `Date` with a real user.\
\
File(s): [`_`](./)

### \[4\]
(D2) Define a class `Histogram` that keeps count of numbers in some intervals specified as arguments to `Histogram`'s constructor. Provide functions to print out the histogram. Handle out-of-range values.\
\
File(s): [`_`](./)

### \[5\]
(D2.5) Complete class `Table` to hold (name,value) pairs. Then modify the desk calculator program from §10.2 to use class `Table` instead of `map`. Compare and contrast the two versions.\
\
File(s): [`_`](./)

### \[6\]
(D2) Rewrite `Tnode` from §X.13\[8\] as a class with constructors, destructors, etc. Define a tree of `Tnodes` as a class with constructors, destructors, etc.\
\
File(s): [`_`](./)

### \[7\]
(D3) Define, implement, and test a set of integers, class `Intset`. Provide union, intersection, and symmetric difference operations.\
\
File(s): [`_`](./)

### \[8\]
(D1.5) Modify class `Intset` into a set of nodes, where `Node` is a structure you define.\
\
File(s): [`_`](./)

### \[9\]
(D3) Define a class for analyzing, storing, evaluating, and printing simple arithmetic expressions consisting of integer constants and the operators `+`, `−`, `*`, and `/`. The public interface should look like this:
```C++
class Expr {
    // ...
public:
    Expr(const char*);
    int eval();
    void print();
};
```
The string argument for the constructor `Expr::Expr()` is the expression. The function `Expr::eval()` returns the value of the expression, and `Expr::print()` prints a representation of the expression on `cout`. A program might look like this:
```C++
Expr x("123/4+123*4−3");
cout << "x = " << x.eval() << "\n";
x.print();
```
Define class `Expr` twice: once using a linked list of nodes as the representation and once using a character string as the representation. Experiment with different ways of printing the expression: fully parenthesized, postfix notation, assembly code, etc.\
\
File(s): [`_`](./)

### \[10\]
(D2) Define a class `Char_queue` so that the public interface does not depend on the representation. Implement `Char_queue` (a) as a linked list and (b) as a vector. Do not worry about concurrency.\
\
File(s): [`_`](./)

### \[11\]
(D3) Design a symbol table class and a symbol table entry class for some language. Have a look at a compiler for that language to see what the symbol table really looks like.\
\
File(s): [`_`](./)

### \[12\]
(D2) Modify the expression class from §X.17[11] to handle variables and the assignment operator `=`. Use the symbol table class from §X.17\[11\].\
\
File(s): [`_`](./)

### \[13\]
(D1) Given this program:
```C++
#include <iostream>

int main()
{
    std::cout << "Hello, world!\n";
}
```
modify it to produce this output:
```
Initialize
Hello, world!
Clean up
```
Do not change `main()` in any way.\
\
File(s): [`_`](./)

### \[14\]
(D2) Define two classes, each with a `static` member, so that the construction of each `static` member involves a reference to the other. Where might such constructs appear in real code? How can these classes be modified to eliminate the order dependence in the constructors?\
\
File(s): [`_`](./)

### \[15\]
(D2.5) Compare class `Date` (§16.3) with your solution to §X.9\[4\] and §X.13\[21\]. Discuss errors found and likely differences in maintenance of the two solutions.\
\
File(s): [`_`](./)

### \[16\]
(D3) Write a function that, given an `istream` and a `vector<string>`, produces a `map<string,vector<int> >` holding each string and the numbers of the lines on which the string
appears. Run the program on a text-file with no fewer than 1,000 lines looking for no fewer than 10 words.\
\
File(s): [`_`](./)
