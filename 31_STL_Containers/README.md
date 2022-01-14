# X.32 STL Containers

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (algorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

The solutions to several exercises for this chapter can be found by looking at the source text of an implementation of the standard library. Do yourself a favor: try to find your own solutions befor looking to see how your library implementer approached the problems.

### \[1\]
(D1.5) Create a `vector<char>` containing the letters of the alphabet in order. Print the elements of that vector in order and in reverse order.\
\
File(s): [`_`](./)

### \[2\]
(D1.5) Create a `vector<string>` and read a list of names of fruits from cin into it. Sort the list and print it.\
\
File(s): [`_`](./)

### \[3\]
(D1.5) Using the `vector` from §X.32\[2\], write a loop to print the names of all fruits with the initial letter `a`.\
\
File(s): [`_`](./)

### \[4\]
(D1) Using the `vector` from §X.32\[2\], write a loop to delete all fruits with the initial letter `a`.\
\
File(s): [`_`](./)

### \[5\]
(D1) Using the `vector` from §X.32\[2\], write a loop to delete all citrus fruits.\
\
File(s): [`_`](./)

### \[6\]
(D1.5) Using the `vector` from §X.32\[2\], write a loop to delete all fruits that you don’t like.\
\
File(s): [`_`](./)

### \[7\]
(D3) Design a `Container` with an interface consisiting of an abstract class as outlined in §3.2.2. Derive a doubly-linked `List`, a singly-linked `Slist`, and a `Vector`, from it. The elements are of some type `Elem`. Use these containers for a few simple tests. Write a critique of the interface provided by `Container` from the point of view of a user. Don’t forget to discuss error handling.\
\
File(s): [`_`](./)

### \[8\]
(D2.5) Define three independent classes: a doubly-linked `List`, a singly-linked `Slist`, and a `Vector`. For simple traversals, define
```C++
class Itor {
public:
    virtual Elem* first();
virtual Elem* next();
};
```
The members return a pointer to an element or the `nullptr` if there is none. Implement iterators for `List`, `Slist`, and `Vector` as classes derived from `Itor`. Compare this design to the abstract `Container` design in §X.32\[7\].\
\
File(s): [`_`](./)

### \[9\]
(D1) Make a version of §X.32\[7\] where the element type is a template argument.\
\
File(s): [`_`](./)

### \[10\]
(D2.5) Given an `Itor` class like the one in §X.32\[8\], consider how to provide iterators for forwards iteration, backwards iteration, iteration over a container that might change during an iteration, and iteration over an immutable container. Org anize this set of iterators so that a user can interchangeably use iterators that provide sufficient functionality for an algorithm. Minimize replication of effort in the implementation of the containers. What other kinds of iterators might a user need? List the strengths and weaknesses of your approach.\
\
File(s): [`_`](./)

### \[11\]
(D1) Make a version of §X.32\[8\] where the element type is a template argument.\
\
File(s): [`_`](./)

### \[12\]
(D3) Design a "truly object-oriented" container holding Object*s as elements. A `Container` (along the lines of §X.32\[7\]) is itself derived (directly or indirectly) from `Object`. Implement a `List`, `Slist`, and `Vector` as outlined in §X.32\[7\] and test them as in §X.32\[7\].\
\
File(s): [`_`](./)

### \[13\]
(D2.5) Generate 10,000 uniformly distributed random numbers in the range 0 to 1,023 and store them in\
(a) a standard library `vector<int>`,\
(b) a `Vector<int>` from §X.32\[7\],\
(c) a `Vector<int>` from §X.32\[8\].\
(d) a `Vector` from §X.32\[12\].\
In each case, calculate the arithmetic mean of the elements of the vector (as if you didn’t know it already). Time the resulting loops. Estimate, measure, and compare the memory consumption for the three styles of vectors.\
\
File(s): [`_`](./)

### \[14\]
(D2) Write a template that implements a container with the same member functions and member types as the standard `vector` for an existing (nonstandard, non-student-exercise) container type. Do not modify the (pre)existing container type. How would you deal with functionality offered by the nonstandard `vector` but not by the standard `vector`?\
\
File(s): [`_`](./)

### \[15\]
(D1.5) What is seriously wrong with this function?:
```C++
void duplicate(vector<string& v) // not the way to do it
{
    for (auto p = v.begin(); p!=v.end(); ++v)
        v.insert(p,*p);
}
```
Outline the possible behavior of `duplicate_elements()` for a `vector<string>` with the three elements (**don't do this**.)\
\
File(s): [`_`](./)

### \[16\]
(D2.5) Understand the "Big-O" notation (§31.3). Do some measurements of operations on standard containers to determine the constant factors involved.\
\
File(s): [`_`](./)

### \[17\]
(D2) Many phone numbers don’t fit into a long. Write a phone_number type and a class that provides a set of useful operations on a container of phone_numbers.\
\
File(s): [`_`](./)

### \[18\]
(D2) Write a program that lists the distinct words in a file in alphabetical order. Make two versions: one in which a word is simply a whitespace-separated sequence of characters and one in which a word is a sequence of letters separated by any sequence of non-letters.\
\
File(s): [`_`](./)

### \[19\]
(D2.5) Implement a simple solitaire card game.\
\
File(s): [`_`](./)

### \[20\]
(D1.5) Implement a simple test of whether a word is a palindrome (that is, if its representation is symmetric; examples are `"ada"`, `"otto"`, and `"tut"`). Implement a simple test of whether an integer is a palindrome. Implement a simple test of whether a sentence is a palindrome. Generalize.\
\
File(s): [`_`](./)

### \[21\]
(D1.5) Define a queue using (only) two stacks.\
\
File(s): [`_`](./)

### \[22\]
(D1.5) Define a stack similar to stack (§31.3.6), except that it doesn’t copy its underlying container and that it allows iteration over its elements.\
\
File(s): [`_`](./)

### \[23\]
(D3) Your computer will have support for concurrent activities through the concept of a thread, task, or process. Figure out how that is done. The concurrency mechanism will have a concept of locking to prevent two tasks accessing the same memory simultaneously. Use the machine’s locking mechanism to implement a lock class.\
\
File(s): [`_`](./)

### \[24\]
(D2.5) Read a sequence of dates such as `Dec85`, `Dec50`, `Jan76`, etc., from input and then output them so that later dates come first. The format of a date is a three-letter month followed by a two-digit year. Assume that all the years are from the same century.\
\
File(s): [`_`](./)

### \[25\]
(D2.5) Generalize the input format for dates to allow dates such as `Dec1985`, `12/3/1990`, `(Dec,30,1950)`, `3/6/2001`, etc. Modify exercise §X.32\[24\] to cope with the new formats.\
\
File(s): [`_`](./)

### \[26\]
(D1.5) Use a `bitset` to print the binary values of some numbers, including `0`, `1`, `−1`, `18`, `−18`, and the largest positive `int`.\
\
File(s): [`_`](./)

### \[27\]
(D1.5) Use `bitset` to represent which students in a class were present on a given day. Read the `bitset`s for a series of 12 days and determine who was present every day. Determine which students were present at least 8 days.\
\
File(s): [`_`](./)

### \[28\]
(D2) Implement and test a doubly-linked list so that an empty list takes up only the space for a `Link*`.\
\
File(s): [`_`](./)

### \[29\]
(D1.5) Write a `List` of pointers that `delete`s the objects pointed to when it itself is destroyed or if the element is removed from the `List`.\
\
File(s): [`_`](./)

### \[30\]
(D1.5) Given a `stack` object, print its elements in order (without changing the value of the stack).\
\
File(s): [`_`](./)

### \[31\]
(D2.5) Implement and test a list in the style of the standard `list`.\
\
File(s): [`_`](./)

### \[32\]
(D2) Sometimes, the space overhead of a `list` can be a problem. Write and test a singly-linked list in the style of a standard container.\
\
File(s): [`_`](./)

### \[33\]
(D2.5) Implement a list that is like a standard `list`, except that it supports subscripting. Compare the cost of subscripting for a variety of lists to the cost of subscripting a `vector` of the same length.\
\
File(s): [`_`](./)

### \[34\]
(D2) Implement a template function that merges two containers.\
\
File(s): [`_`](./)

### \[35\]
(D1.5) Given a C-style string, determine whether it is a palindrome. Determine whether an initial sequence of at least three words in the string is a palindrome.\
\
File(s): [`_`](./)

### \[36\]
(D2) Read a sequence of `(name,value)` pairs and produce a sorted list of `(name,total,mean,median)` 4-tuples. Print that list.\
\
File(s): [`_`](./)

### \[37\]
(D2.5) Determine the space overhead of each of the standard containers on your implementation.\
\
File(s): [`_`](./)

### \[38\]
(D3.5) Consider what would be a reasonable implementation strategy for a `hash_map` that needed to use minimal space. Consider what would be a reasonable implementation strategy for a `hash_map` that needed to use minimal lookup time. In each case, consider what operations you might omit so as to get closer to the ideal (no space overhead and no lookup overhead, respectively). Hint: There is an enormous literature on hash tables.\
\
File(s): [`_`](./)

### \[39\]
(D2) Devise a strategy for dealing with overflow in `hash_map` (different values hashing to the same hash value) that makes `equal_range()` trivial to implement.\
\
File(s): [`_`](./)

### \[40\]
(D2.5) Estimate the space overhead of a `hash_map` and then measure it. Compare the estimate to the measurements. Compare the space overhead of your `hash_map` and your implementation’s `map`.\
\
File(s): [`_`](./)

### \[41\]
(D2.5) Profile your `hash_map` to see where the time is spent. Do the same for your implementation’s `map` and a widely-distributed `hash_map`.\
\
File(s): [`_`](./)

### \[42\]
(D2.5) Implement a `hash_map` based on a `vector<map<K,V>*>` so that each `map` holds all keys that have the same hash value.\
\
File(s): [`_`](./)

### \[43\]
(D3) Implement a `hash_map` using Splay trees (see D. Sleator and R. E. Tarjan: Self-Adjusting Binary Search Trees, JACM, Vol. 32. 1985).\
\
File(s): [`_`](./)

### \[44\]
(D2) Given a data structure describing a string-like entity:
```C++
struct St {
    int size;
    char type_indicator;
    char* buf; // point to size characters
    St(const char* p); // allocate and fill buf
};
```
Create 1000 `St`s and use them as keys for a `hash_map`. Devise a program to measure the performance of the `hash_map`. Write a hash function (a `hash<>`; §31.4.3.4) specifically for `St` keys.\
\
File(s): [`_`](./)

### \[45\]
(D2) Give at least four different ways of removing the erased elements from a `hash_map`. You should use a standard library algorithm (§3.4.2, Chapter 32) to avoid an explicit loop.\
\
File(s): [`_`](./)

### \[46\]
(D3) Implement a `hash_map` that erases elements immediately.\
\
File(s): [`_`](./)

### \[47\]
(D2) Give an example of when it might be wise to ignore part of a key and write a hash function that computes its value based only on the part of a key considered relevant.\
\
File(s): [`_`](./)

### \[48\]
(D3) Given some implementation of `hash_map`, implement `hash_multimap`, `hash_set`, and `hash_multiset`.\
\
File(s): [`_`](./)

### \[49\]
(D2.5) Write a hash function intended to map uniformly distributed int values into hash values intended for a table size of about 1024. Given that function, devise a set of 1024 key values, all of which map to the same value.\
\
File(s): [`_`](./)
