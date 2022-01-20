# X.5 A Tour of C++: Containers and Algorithms

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (algorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
When first reading this chapter, keep a record of information that was new or surprising to you. Later, use that list to focus your further studies.\
\
File(s): N/A

### \[2\]
(D1) List five standard-library containers.\
\
File(s): [`X5_2.txt`](./X5_2.txt)

### \[3\]
(D1) List five standard-library algorithms.\
\
File(s): [`X5_3.txt`](./X5_3.txt)

### \[4\]
(D1) List five standard-library headers.\
\
File(s): [`X5_4.txt`](./X5_4.txt)

### \[5\]
(D1.5) Write a program that reads a name (a `string`) and an age (an `int`) from the standard input stream `cin`. Then output a message including the name and age to the standard output stream `cout`.\
\
File(s): [`X5-5_main.cc`](./X5-5_main.cc)\
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X5-5_main.cc`

### \[6\]
(D1.5) Redo §X.5[5], storing several (name, age) pairs in a class. Doing the reading and writing using your own `>>` and `<<` operators.\
\
File(s): [`X5-6_main.cc`](./X5-6_main.cc) [`X5-6_UserProfile.cc`](./X5-6_UserProfile.cc) [`X5-6_UserProfile.h`](./X5-6_UserProfile.h)\
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X5-6_main.cc X5-6_UserProfile.cc`

### \[7\]
(D2) Initialize a `vector<int>` with the elements `5`, `9`, `−1`, `200`, and `0`. Print it. Sort it, and print it again.\
\
File(s): [`_`](./)\
Compiled: `_`

### \[8\]
(D1) Repeat §X.5\[7\] with a `vector<string>` initialized with `"Kant"`, `"Plato"`, `"Aristotle"`, `"Kierkegard"`, and `"Hume"`.\
\
File(s): [`_`](./)\
Compiled: `_`

### \[9\]
(D1) Open a file for writing (as an `ofstream`) and write a few hundred integers to it.\
\
File(s): [`_`](./)\
Compiled: `_`

### \[10\]
(D1) Open the file of integers from §X.5\[9\] for reading (as an `ifstream`) and read it.\
\
File(s): [`_`](./)\
Compiled: `_`
