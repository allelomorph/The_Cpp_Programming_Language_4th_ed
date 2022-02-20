# X.20 Special Operations

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (logorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D2) Complete class `Ptr` from §19.2.4 and test it. To be complete, Ptr must have at least the operators `*`, `−>`, `=`, `++`, and `−−` defined. Do not cause a run-time error until a wild pointer is actually dereferenced.\
\
File(s): [`_`](./)

### \[2\]
(D2) Define an external iterator for class String:
```C++
class String_iter {
    // refer to string and string element
public:
    String_iter(String& s); // iterator for s
    char& next(); // reference to next element

    // more operations of your choice
};
```
Compare this in utility, programming style, and efficiency to having an internal iterator for `String` (that is, a notion of a current element for the `String` and operations relating to that element).\
\
File(s): [`_`](./)

### \[3\]
(D1.5) Provide a substring operator for a string class by overloading `()`. What other operations would you like to be able to do on a string?\
\
File(s): [`_`](./)

### \[4\]
(D3) Design class `String` so that the substring operator can be used on the left-hand side of an assignment. First, write a version in which a string can be assigned to a substring of the same length. Then, write a version in which the lengths may differ.\
\
File(s): [`_`](./)

### \[5\]
(D2) Define an operation for String that produces a C-string representation of its value. Discuss the pros and cons of having that operation as a conversion operator. Discuss alternatives for allocating the memory for that C-string representation.\
\
File(s): [`_`](./)

### \[6\]
(D2.5) Define and implement a simple regular expression pattern match facility for class `String`.\
\
File(s): [`_`](./)

### \[7\]
(D1.5) Modify the pattern match facility from §X.20\[6\] to work on the standard library string. Note that you cannot modify the definition of string.\
\
File(s): [`_`](./)
