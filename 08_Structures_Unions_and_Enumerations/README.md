# X.9 Structures, Unions, and Enumerations

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (algorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D1) Define a `struct` with a member of each of the types `bool`, `char`, `int`, `long`, `double`, and `long double`. Order the members so as to get the largest size of the struct and the smallest size of the struct.\
\
File(s): [`X9-1_main.cc`](./X9-1_main.cc)
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X9-1_main.cc`

### \[2\]
(D1.5) Define a table of the names of months of the year and the number of days in each month. Write out that table. Do this twice; once using an array of `char` for the names and an array for the number of days and once using an array of structures, with each structure holding the name of a month and the number of days in it.\
\
File(s): [`X9-2_main.cc`](./X9-2_main.cc)
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X9-2_main.cc`

### \[3\]
(D1.5) Find an example where it would make sense to use a name in its own initializer.\
\
File(s): [`X9-3.txt`](./X9-3.txt)

### \[4\]
(D1.5) Define a `struct Date` to keep track of dates. Provide functions that read `Date`s from input, write `Date`s to output, and initialize a `Date` with a date.\
\
File(s): [`_`](./)

### \[5\]
(D2) Implement an `enum` called `Season` with enumerators `spring`, `summer`, `autumn`, and `winter`. Define operators `++` and `−−` for Season. Define input (`>>`) and output (`<<`) operations for `Season`, providing string values. Provide a way to control the mapping between `Season` values and their string representations. For example, I might want the strings to reflect the Danish names for the seasons. For further study, see Chapter 39.\
\
File(s): [`X9-5_main.cc`](./X9-5_main.cc)
Compiled: `g++ -Wall -Werror -Wextra -pedantic -std=c++11 X9-5_main.cc`
