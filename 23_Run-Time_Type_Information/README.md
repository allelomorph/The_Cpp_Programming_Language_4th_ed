# X.23 Run-Time Type Information

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (algorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D1) Write a template `ptr_cast` that works like `dynamic_cast`, except that it throws `bad_cast` rather than returning `0`.\
\
File(s): [`_`](./)

### \[2\]
(D2) Write a program that illustrates the sequence of constructor calls at the state of an object relative to RTTI during construction. Similarly illustrate destruction.\
\
File(s): [`_`](./)

### \[3\]
(D3) Consider how `dynamic_cast` might be implemented. Define and implement a `dcast` template that behaves like `dynamic_cast` but relies on functions and data you define only. Make sure that you can add new classes to the system without having to change the definitions of `dcast` or previously-written classes.\
\
File(s): [`_`](./)

### \[4\]
(D3) What information would you like to have associated with a class to be accessible at runtime? Implement and association scheme as outlined in §22.5.1 as an `unordered_map<type_index,My_info*>` (§35.5.4). First make a simple version where `My_info` just holds a string associated with the class (e.g., a comment about its purpose). Second, implement a version that does what you want (e.g. holds a table of member function names and pointers to member functions).\
\
File(s): [`_`](./)
