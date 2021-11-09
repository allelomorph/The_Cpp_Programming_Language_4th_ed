# X.39 I/O Streams

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (algorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D1.5) Read a file of floating-point numbers, make complex numbers out of pairs of numbers read, and write out the complex numbers.\
\
File(s): [`_`](./)

### \[2\]
(D1.5) Define a type `Name_and_address`. Define `<<` and `>>` for it. Copy a stream of `Name_and_address` objects.\
\
File(s): [`_`](./)

### \[3\]
(D2.5) Copy a stream of `Name_and_address` objects in which you have inserted as many errors as you can think of (e.g., format errors and premature end of string). Handle these errors in a way that ensures that the copy function reads most of the correctly formatted `Name_and_addresses`, even when the input is completely messed up.\
\
File(s): [`_`](./)

### \[4\]
(D2.5) Redefine the I/O format of `Name_and_address` to make it more robust in the presence of format errors.\
\
File(s): [`_`](./)

### \[5\]
(D2.5) Design some functions for requesting and reading information of various types. Ideas: integer, floating-point number, file name, mail address, date, personal information, etc. Try to make them foolproof.\
\
File(s): [`_`](./)

### \[6\]
(D1.5) Write a program that prints (a) all lowercase letters, (b) all letters, (c) all letters and digits, (d) all characters that may appear in a C++ identifier on your system, (e) all punctuation characters, (f) the integer value of all control characters, (g) all whitespace characters, (h) the integer value of all whitespace characters, and finally (i) all printing characters.\
\
File(s): [`_`](./)

### \[7\]
(D2) Read a sequence of lines of text into a fixed-sized character buffer. Remove all whitespace characters and replace each alphanumeric character with the next character in the alphabet (replace z by a and 9 by 0). Write out the resulting line.\
\
File(s): [`_`](./)

### \[8\]
(D3) Write a "miniature" stream I/O system that provides classes `istream`, `ostream`, `ifstream`, `ofstream` providing functions such as `operator<<()` and `operator>>()` for integers and operations such as `open()` and `close()` for files.\
\
File(s): [`_`](./)

### \[9\]
(D4) Implement the C standard I/O library (`<stdio.h>`) using the C++ standard I/O library (`<iostream>`).\
\
File(s): [`_`](./)

### \[10\]
(D4) Implement the C++ standard I/O library (`<iostream>`) using the C standard I/O library (`<stdio.h>`).\
\
File(s): [`_`](./)

### \[11\]
(D4) Implement the C and C++ libraries so that they can be used simultaneously.\
\
File(s): [`_`](./)

### \[12\]
(D2) Implement a class for which `[]` is overloaded to implement random reading of characters from a file.\
\
File(s): [`_`](./)

### \[13\]
(D3) Repeat §X.39\[12\] but make `[]` useful for both reading and writing. Hint: Make `[]` return an object of a "descriptor type" for which assignment means "assign through descriptor to file" and implicit conversion to `char` means "read from file through descriptor."\
\
File(s): [`_`](./)

### \[14\]
(D2) Repeat §X.39\[13\] but let `[]` index objects of arbitrary types, not just characters.\
\
File(s): [`_`](./)

### \[15\]
(D3.5) Implement versions of `istream` and `ostream` that read and write numbers in their binary form rather than converting them into a character representation. Discuss the advantages and disadvantages of this approach compared to the character-based approach.\
\
File(s): [`_`](./)

### \[16\]
(D3.5) Design and implement a pattern-matching input operation. Use `printf`-style format strings to specify a pattern. It should be possible to try out several patterns against some input to find the actual format. One might derive a pattern-matching input class from `istream`.\
\
File(s): [`_`](./)

### \[17\]
(D4) Invent (and implement) a much better kind of pattern for pattern matching. Be specific about what is better about it.\
\
File(s): [`_`](./)

### \[18\]
(D2) Define an output manipulator `based` that takes two arguments – a base and an `int` value – and outputs the integer in the representation specified by the base. For example, `based(2,9)` should print `1001`.\
\
File(s): [`_`](./)

### \[19\]
(D2) Write manipulators that turn character echoing on and off.\
\
File(s): [`_`](./)

### \[20\]
(D2) Implement `Bound_form` from §38.4.5.3 for the usual set of built-in types.\
\
File(s): [`_`](./)

### \[21\]
(D2) Re-implement `Bound_form` from §38.4.5.3 so that an output operation never overflows its `width()`. It should be possible for a programmer to ensure that output is never quietly truncated beyond its specified precision.\
\
File(s): [`_`](./)

### \[22\]
(D3) Implement an `encrypt(k)` manipulator that ensures that output on its `ostream` is encrypted using the key `k`. Provide a similar `decrypt(k)` manipulator for an `istream`. Provide the means for turning the encryption off for a stream so that further I/O is cleartext.\
\
File(s): [`_`](./)

### \[23\]
(D2) Trace a character’s route through your system from the keyboard to the screen for a simple:
```C++
char c;
cin >> c;
cout << c << endl;
```
\
\
File(s): [`_`](./)

### \[24\]
(D2.5) There is a standard way of reading, writing, and representing dates under control of a `locale`. Find it in the documentation of your implementation and write a small program that reads and writes dates using this mechanism. Hint: `struct tm`.\
\
File(s): [`_`](./)

### \[25\]
(D2.5) Define an `ostream` called `ostrstream` that can be attached to an array of characters (a C-style string) in a way similar to the way `ostringstream` is attached to a `string`. However, do not copy the array into or out of the `ostrstream`. The `ostrstream` should simply provide a way of writing to its array argument. It might be used for in-memory formatting like this:
```C++
char buf[message_size];
ostrstream ost(buf,message_size);
do_something(arguments,ost);  // output to buf through ost
cout << buf;  // ost adds terminating 0
```
An operation such as `do_something()` can write to the stream `ost`, pass `ost` on to its suboperations, etc., using the standard output operations. There is no need to check for overflow because `ost` knows its size and will go into `fail()` state when it is full. Finally, a `display()` operation can write the message to a "real" output stream. This technique can be most useful for coping with cases in which the final display operation involves writing to something more complicated than a traditional line-oriented output device. For example, the text from `ost` could be placed in a fixed-sized area somewhere on a screen. Similarly, define class `istrstream` as an input string stream reading from a zero-terminated string of characters. Interpret the terminating zero character as end-of-file. These `strstreams` were part of the original streams library and can often be found in `<strstream.h>`.\
\
File(s): [`_`](./)
