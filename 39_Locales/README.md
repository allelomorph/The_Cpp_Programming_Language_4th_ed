# X.40 Locales

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (logorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D2.5) Define a `Season_io` (§39.3.2) for a language other than American English.\
\
File(s): [`_`](./)

### \[2\]
(D2) Define a `Season_io` (§39.3.2) class that takes a set of name strings as a constructor argument so that `Season` names for different locales can be represented as objects of this class.\
\
File(s): [`_`](./)

### \[3\]
(D3) Write a `collate<char>::compare()` that gives dictionary order. Preferably, do this for a language, such as German or French, that has more letters in its alphabet than English does.\
\
File(s): [`_`](./)

### \[4\]
(D2) Write a program that reads and writes bools as numbers, as English words, and as words in another language of your choice.\
\
File(s): [`_`](./)

### \[5\]
(D2.5) Define a `Time` type for representing time of day. Define a `Date_and_time` type by using `Time` and a `Date` type. Discuss the pros and cons of this approach compared to the `Date` from (§39.4.4). Implement `locale`-sensitive I/O for `Time` and `Date_and_time`.\
\
File(s): [`_`](./)

### \[6\]
(D2.5) Design and implement a postal code (zip code) facet. Implement it for at least two countries with dissimilar conventions for writing addresses. For example: `NJ 07932` and `CB21QA`.\
\
File(s): [`_`](./)

### \[7\]
(D2.5) Design and implement a phone number facet. Implement it for at least two countries with dissimilar conventions for writing phone numbers. For example, `(973) 360−8000` and `1223 343000`.\
\
File(s): [`_`](./)

### \[8\]
(D2.5) Experiment to find out what input and output formats your implementation uses for date information.\
\
File(s): [`_`](./)

### \[9\]
(D2.5) Define a `get_time()` that "guesses" about the meaning of ambiguous dates, such as `12/5/1995`, but still rejects all or almost all mistakes. Be precise about what "guesses" are accepted, and discuss the likelihood of a mistake.\
\
File(s): [`_`](./)

### \[10\]
(D2) Make a list of the locales supported on your system.\
\
File(s): [`_`](./)

### \[11\]
(D2.5) Figure out where named locales are stored on your system. If you have access to the part of the system where locales are stored, make a new named locale. Be very careful not to break existing locales\
\
File(s): [`_`](./)

### \[12\]
(D2) Compare the two `Season_io` implementations (§39.3.2 and §39.4.7.1).\
\
File(s): [`_`](./)

### \[13\]
(D2.5) Implement I/O of Roman numerals (such as `XI` and `MDCLII`).\
\
File(s): [`_`](./)

### \[14\]
(D2.5) Implement and test `Cvt_to_upper` (§39.4.6).\
\
File(s): [`_`](./)

### \[15\]
(D2.5) Use `clock()` to determine average cost of (1) a function call, (2) a virtual function call, (3) reading a `char`, (4) reading a 1-digit `int`, (5) reading a 5-digit `int`, (6) reading a 5-digit `double`, (7) a 1-character `string`, (8) a 5-character `string`, and (9) a 40-character `string`.\
\
File(s): [`_`](./)
