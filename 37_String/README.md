# X.37 String

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (algorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

The solutions to several exercises for this chapter can be found by looking at the source text of an implementation of the standard library. Do yourself a favor: try to find your own solutions before looking to see how your library implementer approached the problems.

### \[1\]
(D2) Write a function that takes two `string`s and returns a `string` that is the concatenation of the strings with a dot in the middle. For example, given `"file"` and `"write"`, the function returns `"file.write"`. Do the same exercise with C-style strings using only C facilities such as `malloc()` and `strlen()`. Compare the two functions. What are reasonable criteria for a comparison?\
\
File(s): [`_`](./)

### \[2\]
(D2) Make a list of differences between `vector` and `basic_string`. Which differences are important?\
\
File(s): [`_`](./)

### \[3\]
(D2) The string facilities are not perfectly regular. For example, you can assign a `char` to a string, but you cannot initialize a `string` with a `char`. Make a list of such irregularities. Which could have been eliminated without complicating the use of strings? What other irregularities would this introduce?\
\
File(s): [`_`](./)

### \[4\]
(D1.5) Class `basic_string` has a lot of members. Which could be made nonmember functions without loss of efficiency or notational convenience?\
\
File(s): [`_`](./)

### \[5\]
(D1.5) Write a version of `back_inserter()` (§33.2.2) that works for `basic_string`.\
\
File(s): [`_`](./)

### \[6\]
(D2) Complete `Basic_substring` from §36.3.8 and integrate it with a `String` type that overloads `()` to mean "substring of" and otherwise acts like string.\
\
File(s): [`_`](./)

### \[7\]
(D2.5) Write a `find()` function that finds the first match for a simple regular expression in a `string`. Use `?` to mean "any character," `*` to mean any number of characters not matching the next part of the regular expression, and `[abc]` to mean any character from the set specified between the square braces (here `a`, `b`, and `c`). Other characters match themselves. For example, `find(s,"name:")` returns a pointer to the first occurrence of `name:` in `s`; `find(s,"[nN]ame:")` returns a pointer to the first occurrence of `name:` or `Name:` in `s`; and `find(s,"[nN]ame(D)")` returns a pointer to the first occurence of `Name` or `name` followed by a (possibly empty) parenthesized sequence of characters in `s`.\
\
File(s): [`_`](./)

### \[8\]
(D2.5) What operations do you find missing from the simple regular expression function from §X.37\[7\]? Specify and add them. Compare the expressiveness of your regular expression matcher to that of a widely distributed one. Compare the performance of your regular expression matcher to that of a widely distributed one.\
\
File(s): [`_`](./)

### \[9\]
(D2.5) Use a regular expression library to implement pattern-matching operations on a `String` class that has an associated `Substring` class.\
\
File(s): [`_`](./)

### \[10\]
(D2.5) Consider writing an "ideal" class for general text processing. Call it `Text`. What facilities should it have? What implementation constraints and overheads are imposed by your set of "ideal" facilities?\
\
File(s): [`_`](./)

### \[11\]
(D1.5) Define a set of overloaded versions for `isalpha()`, `isdigit()`, etc., so that these functions work correctly for `char`, `unsigned char`, and `signed char`.\
\
File(s): [`_`](./)

### \[12\]
(D2.5) Write a `String` class optimized for strings having no more than eight characters. Compare its performance to that of the `String` from §19.3 and your implementation’s version of the standard library `string`.\
\
File(s): [`_`](./)

### \[13\]
(D2) Measure the performance of copying of `string`s. Does your implementation’s implementation of `string` adequately optimize copying?\
\
File(s): [`_`](./)

### \[14\]
(D2.5) Imagine that reading medium-long strings (most are 5 to 25 characters long) from `cin` is the bottleneck in your system. Write an input function that reads such strings as fast as you can think of. You can choose the interface to that function to optimize for speed rather than for convenience. Compare the result to your implementation’s `>>` for `string`s.\
\
File(s): [`_`](./)

### \[15\]
(D1.5) Write a function `itos(int)` that returns a string representing its `int` argument.\
\
File(s): [`_`](./)
