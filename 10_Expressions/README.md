# X.11 Expressions

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (algorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D1) Fully parenthesize the following expressions:
```C++
a = b + c * d << 2 & 8
a & 077 != 3
a == b || a == c && c < 5
c = x != 0
0 <= i < 7
f(1,2)+3
a = − 1 + + b −− − 5
a = b == c ++
a = b = c = 0
a[4][2] *= * b ? c : * d * 2
a−b,c=d
```
\
File(s): [`X11-1.txt`](./X11-1.txt)

### \[2\]
(D2) Read a sequence of possibly whitespace-separated (name,value) pairs, where the name is a single whitespace-separated word and the value is an integer or a floating-point value. Compute and print the sum and mean for each name and the sum and mean for all names. Hint: §10.2.8.\
\
File(s): [`X11-2_main.cc`](./X11-2_main.cc)
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X11-2_main.cc`

### \[3\]
(D1) Write a table of values for the bitwise logical operations (§11.1.1) for all possible combinations of `0` and `1` operands.\
\
File(s): [`X11-2_main.cc`](./X11-3_main.cc)
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X11-3_main.cc`

### \[4\]
(D2) Write 5 expressions for which the order of evaluation is undefined. Execute them to see what one or – preferably – more implementations do with them.\
\
File(s): [`_`](./)

### \[5\]
(D1.5) What happens if you divide by zero on your system? What happens in case of overflow and underflow?\
\
File(s): [`X11-5_main.cc`](./X11-5_main.cc)
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 -Wno-div-by-zero X11-5_main.cc`

### \[6\]
(D1) Fully parenthesize the following expressions:
```C++
*p++
*−−p
++a−−
(int*)p−>m
*p.m
*a[i]
```
\
File(s): [`X11-6.txt`](./X11-6.txt)

### \[7\]
(D2) Implement and test these functions: `strlen()`, which returns the length of a C-style string; `strcpy()`, which copies a C-style string into another; and `strcmp()`, which compares two C-style strings. Consider what the argument types and return types ought to be. Then compare your functions with the standard library versions as declared in `<cstring>` (`<string.h>`) and as specified in §43.4.\
\
File(s): [`_`](./)

### \[8\]
(D2) Modify the program from §X.11\[3\] to also compute the median.\
\
File(s): [`_`](./)

### \[9\]
(D2) Write a function `cat()` that takes two C-style string arguments and returns a string that is the concatenation of the arguments. Use `new` to find store for the result.\
\
File(s): [`_`](./)

### \[10\]
(D2) Write a function `rev()` that takes a C-style string argument and reverses the characters in it. That is, after `rev(p)` the last character of `p` will be the first, etc.\
\
File(s): [`_`](./)

### \[11\]
(D2) Type in the calculator example and get it to work. Do not "save time" by using an already entered text. You’ll learn most from finding and correcting "little silly errors."\
\
File(s): [`_`](./)

### \[12\]
(D2) Modify the calculator to report line numbers for errors.\
\
File(s): [`_`](./)

### \[13\]
(D3) Allow a user to define functions in the calculator. Hint: Define a function as a sequence of operations just as a user would have typed them. Such a sequence can be stored either as a character string or as a list of tokens. Then read and execute those operations when the function is called. If you want a user-defined function to take arguments, you will have to invent a notation for that.\
\
File(s): [`_`](./)

### \[14\]
D1.5) Convert the desk calculator to use a symbol structure instead of using the static variables number_value and string_value.\
\
File(s): [`_`](./)
