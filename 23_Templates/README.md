# X.24 Templates

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (algorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D2) Fix the errors in the definition of `List` from §23.3.2 and write out C++ code equivalent to what the compiler must generate for the definition of `List` and the function `f()`. Run a small test case using your hand-generated code and the code generated by the compiler from the template version. If possible on your system given your knowledge, compare the generated code.\
\
File(s): [`_`](./)

### \[2\]
(D3) Write a singly-linked list class template that accepts elements of any type derived from a class Link that holds the information necessary to link elements. This is called an *intrusive list*. Using this list, write a singly-linked list that accepts elements of any type (a non-intrusive list). Compare the performance of the two list classes and discuss the tradeoffs between them.\
\
File(s): [`_`](./)

### \[3\]
(D2.5) Write intrusive and non-intrusive doubly-linked lists. What operations should be provided in addition to the ones you found necessary to supply for a singly-linked list?\
\
File(s): [`_`](./)

### \[4\]
(D2) Complete the `String` template from §23.2 based on the `String` class from §19.3.\
\
File(s): [`_`](./)

### \[5\]
(D2) Define a `sort()` that takes its comparison criterion as a template argument. Define a class `Record` with two data members `count` and `price`. Sort a `vector<Record>` on each data member.\
\
File(s): [`_`](./)

### \[6\]
(D2) Implement a `qsort()` template.\
\
File(s): [`_`](./)

### \[7\]
(D2) Write a program that reads (key,value) pairs and prints out the sum of the values corresponding to each distinct key. Specify what is required for a type to be a key and a value.\
\
File(s): [`_`](./)

### \[8\]
(D2.5) Implement a simple `Map` class based on the `Assoc` class from §19.2.1. Make sure `Map` works correctly using both C-style strings and strings as keys. Make sure `Map` works correctly for types with and without default constructors. Provide a way of iterating over the elements of a `Map`.\
\
File(s): [`_`](./)

### \[9\]
(D3) Compare the performance of the word count program from §19.2.1 against a program not using an associative array. Use the same style of I/O in both cases.\
\
File(s): [`_`](./)

### \[10\]
(D3) Re-implement `Map` from §X.24\[8\] using a more suitable data structure (e.g., a red-black tree or a Splay tree).\
\
File(s): [`_`](./)

### \[11\]
(D2.5) Use `Map` to implement a topological sort function. Topological sort is described in [Knuth,1968] vol. 1 (second edition), pg 262.\
\
File(s): [`_`](./)

### \[12\]
(D1.5) Make the sum program from §X.24[7] work correctly for names containing spaces; for example, "thumb tack."\
\
File(s): [`_`](./)

### \[13\]
(D2) Write `readline()` templates for different kinds of lines. For example (item,count,price).\
\
File(s): [`_`](./)

### \[14\]
(D1.5) Construct an example that demonstrates at least three differences between a function template and a macro (not counting the differences in definition syntax).\
\
File(s): [`_`](./)

### \[15\]
(D2) Devise a scheme that ensures that the compiler tests general constraints on the template arguments for every template for which an object is constructed. It is not sufficient just to test constraints of the form "the argument `T` must be a class derived from `My_base`".\
\
File(s): [`_`](./)