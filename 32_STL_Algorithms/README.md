# X.33 STL Algorithms

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (logorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

The solutions to several exercises for this chapter can be found by looking at the source text of an implementation of the standard library. Do yourself a favor: try to find your own solutions before looking to see how your library implementer approached the problems.

### \[1\]
(D2) Understand the Big-O notation. Give a realistic example in which an *O(N*N)* algorithm is faster than an *O(N)* algorithm for some N>10.\
\
File(s): [`_`](./)

### \[2\]
(D1) Write an algorithm `match()` that is like `mismatch()`, except that it returns iterators to the first corresponding pair that matches the predicate.\
\
File(s): [`_`](./)

### \[3\]
(D1.5) Implement and test `Print_name` from §32.4.1.\
\
File(s): [`_`](./)

### \[4\]
(D1) Sort a `list` using only standard library algorithms.\
\
File(s): [`_`](./)

### \[5\]
(D2.5) Define a class `Iseq` so that `Iseq(p,q)` can be used for a pair of iterators (`p`, `q`) that represent a input sequence. Test is for built-in arrays, istreams, and vectors. Define a suitable set of overloads for the nonmodifying standard algorithms (§32.4) for `Iseq`s. Discuss how best to avoid ambiguities and an explosion in the number of template functions.\
\
File(s): [`_`](./)

### \[6\]
(D2) Define a class `Oseq` to complement `Iseq`. The output sequence given as the argument to `Oseq` should be replaced by the output produced by an algorithm using it. Define a suitable set of overloads for at least three standard algorithms of your choice.\
\
File(s): [`_`](./)

### \[7\]
(D1.5) Produce a `vector` of squares of numbers 1 through 100. Print a table of squares. Take the square root of the elements of that `vector` and print the resulting vector.\
\
File(s): [`_`](./)

### \[8\]
(D2) Write a set of functional objects that do bitwise logical operations on their operands. Test these objects on vectors of `char`, `int`, and `bitset<67>`.\
\
File(s): [`_`](./)

### \[9\]
(D1) Write a `binder3()` that binds the second and third arguments of a three-argument function to produce a unary predicate. Give an example where `binder3()` is a useful function.\
\
File(s): [`_`](./)

### \[10\]
(D1.5) Write a small program that that removes adjacent repeated words from from a file file. Hint: The program should remove a `that`, a `from`, and a `file` from the previous statement.
[11] (D2.5) Define a format for records of references to papers and books kept in a file. Write a program that can write out records from the file identified by year of publication, name of author, keyword in title, or name of publisher. The user should be able to request that the output be sorted according to similar criteria.\
\
File(s): [`_`](./)

### \[12\]
(D2) Implement a `move()` algorithm in the style of `copy()` in such a way that the input and output sequences can overlap. Be reasonably efficient when given random-access iterators as arguments.\
\
File(s): [`_`](./)

### \[13\]
(D1.5) Produce all anagrams of the word `"food"`. That is, all four-letter combinations of the letters `'f'`, `'o'`, `'o'`, and `'d'`. Do not generate duplicates. Generalize this program to take a word as input and produce anagrams of that word.\
\
File(s): [`_`](./)

### \[14\]
(D1.5) Write a program that produces anagrams of sentences; that is, a program that produces all permutations of the words in the sentences (rather than permutations of the letters in the words).\
\
File(s): [`_`](./)

### \[15\]
(D1.5) Implement `find_if()` (§32.4.4) and then implement `find()` using `find_if()`. Find a way of doing this so that the two functions do not need different names.\
\
File(s): [`_`](./)

### \[16\]
(D2) Implement `search()` (§32.4.6). Provide an optimized version for random-access iterators.\
\
File(s): [`_`](./)

### \[17\]
(D2) Take a sort algorithm (such as `sort()` from your standard library or the Shell sort from §23.5) and insert code so that it prints out the sequence being sorted after each swap of elements.\
\
File(s): [`_`](./)

### \[18\]
(D2) There is no `sort()` for bidirectional iterators. The conjecture is that copying to a vector and then sorting is faster than sorting a sequence using bidirectional iterators. Implement a general sort for bidirectional iterators and test the conjecture.\
\
File(s): [`_`](./)

### \[19\]
(D2.5) Imagine that you keep records for a group of sports fishermen. For each catch, keep a record of species, length, weight, date of catch, name of fisherman, etc. Sort and print the records according to a variety of criteria. Hint: `inplace_merge()`.\
\
File(s): [`_`](./)

### \[20\]
(D2) Create lists of students taking Math, English, French, and Biology. Pick about 20 names for each class out of a set of 40 names. List students who take both Math and English. List students who take French but not Biology or Math. List students who do not take a science course. List students who take French and Math but neither English nor Biology.\
\
File(s): [`_`](./)

### \[21\]
(D1.5) Write a `remove()` function that actually removes elements from a container.\
\
File(s): [`_`](./)
