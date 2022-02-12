# X.10 Statements

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (algorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D1) Rewrite the following `for`-statement as an equivalent `while`-statement:
```C++
for (i=0; i!=max_length; i++)
    if (input_line[i] == '?')
        quest_count++;
```
Rewrite it to use a pointer as the controlled variable, that is, so that the test is of the form `*p=='?'`. Rewrite it to use a range-`for`.\
\
File(s): [`X10-1.txt`](./X10-1.txt)

### \[2\]
(D1) See how your compiler reacts to these errors:
```C++
void f(int a, int b)
{
    if (a = 3) // ...
    if (a&077 == 0) // ...
    a := b+1;
}
```
Devise more simple errors and see how the compiler reacts.\
\
File(s): [`_`](./)

### \[3\]
(D1.5) What does the following example do?
```C++
void send(int* to, int* from, int count) // Duff’s device. Helpful comment deliberately deleted.
{
    int n = (count+7)/8;

    switch (count%8) {

    case 0: do { *to++ = *from++;
    case 7:      *to++ = *from++;
    case 6:      *to++ = *from++;
    case 5:      *to++ = *from++;
    case 4:      *to++ = *from++;
    case 3:      *to++ = *from++;
    case 2:      *to++ = *from++;
    case 1:      *to++ = *from++;
        } while (−−n>0);
    }
}
```
Why would anyone write something like that? No, this is not recommended as good style.\
\
File(s): [`X10-3_main.cc`](./X10-3_main.cc)
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X10-3_main.cc`

### \[4\]
(D2) Write a function `atoi(const char*)` that takes a C-style string containing digits and returns
the corresponding `int`. For example, `atoi("123")` is `123`. Modify `atoi()` to handle C++ octal and
hexadecimal notation in addition to plain decimal numbers. Modify `atoi()` to handle the C++
character constant notation.\
\
File(s): [`X10-4_main.cc`](./X10-4_main.cc)
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X10-4_main.cc`

### \[5\]
(D2) Write a function `itoa(int i, char b[])` that creates a string representation of `i` in `b` and returns `b`.\
\
File(s): [`X10-5_main.cc`](./X10-5_main.cc)
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X10-5_main.cc`

### \[6\]
Modify `iota()` from the previous exercise to take an extra "string length" argument to make overflow less likely.\
\
File(s): [`X10-6_main.cc`](./X10-6_main.cc)
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X10-6_main.cc`

### \[7\]
(D2.5) Write a program that strips comments out of a C++ program. That is, read from `cin`, remove both `//` comments and `/* */` comments, and write the result to `cout`. Do not worry about making the layout of the output look nice (that would be another, and much harder, exercise). Do not worry about incorrect programs. Beware of `//`, `/*`, and `*/` in comments, strings, and character constants.\
\
File(s): [`_`](./)

### \[8\]
(D2) Look at some programs to get an idea of the variety of indentation, naming, and commenting styles actually used.\
\
File(s): [`_`](./)
