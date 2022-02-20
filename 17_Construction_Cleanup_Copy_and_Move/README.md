# X.18 Construction, Cleanup, Copy, and Move

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (logorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D2) Implement the functions of the "cannonical complete class" `X` from §17.1 to do noting but print out their name and the address of their object (and of their argument where applicable). Now test `X` by defining variables, members, objects on the free store, passing arguments, etc.\
\
File(s): [`_`](./)

### \[2\]
(D2) Define a resource handle, a "smart pointer" that holds a pointer to an object on the free store passed as an argument to a constructor. "Forget" to define copy operations. Now test the handle by defining variables, members, objects on the free store, passing arguments, etc., and see where leaks occur.\
\
File(s): [`_`](./)

### \[3\]
(D1.5) When do you need a constructor? When do memberwise construction suffice? When is memberwise construction preferable?\
\
File(s): [`_`](./)

### \[4\]
(D1) Design, implement and test a `Vector` class with an initializer-list constructor and no constructor that takes a integer as a size. Instead, give it a constructor that takes a `Count` type, so that you can’t get ambiguities between and integer number of elements and an integer element value.\
\
File(s): [`_`](./)

### \[5\]
(D3) Write an extremely simple document editor with only three commands: "Insert a string as line number n," "delete line n," and "undo the last (non-undo) operation." In addition, provide a cursor to a character in the document (or one beyond the last character) that can be moved forwards and backwards. Do not let any command lead to an invalid cursor. Hint: §17.5.1.3.\
\
File(s): [`_`](./)

### \[6\]
(D3) Implement a simple `Matrix` along the lines of the one in §17.5.2. Measure the performance of an addition of 1000-by-1000 matrices with and without move operations. If you did not have the option of adding move operations, what would you do?\
\
File(s): [`_`](./)
