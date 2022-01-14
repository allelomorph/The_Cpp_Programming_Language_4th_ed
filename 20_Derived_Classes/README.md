# X.21 Derived Classes

## Environment
- Ubuntu 20.04.3 LTS
- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## Key
- DX: Stroustrup difficulty rating (algorithmic: D1 = ~10 minutes, D2 = ~1 hour, D3 = ~1 day)

---

### \[1\]
(D1) Define
```C++
class Base {
public:
    virtual void iam() { cout << "Base\n"; }
};
```
Derive two classes from `Base`, and for each define `iam()` to write out the name of the class. Create objects of these classes and call `iam()` for them. Assign pointers to objects of the derived classes to `Base*` pointers and call `iam()` through those pointers.\
\
File(s): [`_`](./)

### \[2\]
(D3.5) Implement a simple graphics system using whatever graphics facilities are available on your system (if you don’t have a good graphics system or have no experience with one, you might consider a simple "huge bit ASCII implementation" where a point is a character position and you write by placing a suitable character, such as `*` in a position): `Window(n,m)` creates an area of size `n` times `m` on the screen. Points on the screen are addressed using (x,y) coordinates (Cartesian). A `Window w` has a current position `w.current()`. Initially, current is `Point(0,0)`. The current position can be set by `w.current(p)` where `p` is a `Point`. A `Point` is specified by a coordinate pair: `Point(x,y)`. A `Line` is specified by a pair of `Point`s: `Line(w.current(),p2);` class `Shape` is the common interface to `Dot`s, `Line`s, `Rectangle`s, `Circle`s, etc. A `Point` is not a `Shape`. A `Dot`, `Dot(p)` can be used to represent a `Point p` on the screen. A `Shape` is invisible unless `draw()`n.\
\
For example: `w.draw(Circle(w.current(),10))`. Every `Shape` has 9 contact points: `e` (east), `w` (west), `n` (north), `s` (south), `ne`, `nw`, `se`, `sw`, and `c` (center). For example, `Line(x.c(),y.nw())` creates a line from `x`'s center to `y`'s top left corner. After `draw()`ing a `Shape` the current position is the `Shape`'s `se()`. A `Rectangle` is specified by its bottom left and top right corner: `Rectangle(w.current(),Point(10,10))`. As a simple test, display a simple "child’s drawing of a house" with a roof, two windows, and a door.\
\
File(s): [`_`](./)

### \[3\]
(D2) Important aspects of a `Shape` appear on the screen as a set of line segments. Implement operations to vary the appearance of these segments: `s.thickness(n)` sets the line thickness to `0`, `1`, `2`, or `3`, where `2` is the default and `0` means invisible. In addition, a line segment can be `solid`, `dashed`, or `dotted`. This is set by the function `Shape::outline()`.\
\
File(s): [`_`](./)

### \[4\]
(D2.5) Provide a function `Line::arrowhead()` that adds arrow heads to an end of a line. A line has two ends and an arrowhead can point in two directions relative to the line, so the argument or arguments to `arrowhead()` must be able to express at least four alternatives.\
\
File(s): [`_`](./)

### \[5\]
(D3.5) Make sure that points and line segments that fall outside the `Window` do not appear on the screen. This is often called "clipping." As an exercise only, do not rely on the implementation graphics system for this.\
\
File(s): [`_`](./)

### \[6\]
(D2.5) Add a `Text` type to the graphics system. A `Text` is a rectangular `Shape` displaying characters. By default, a character takes up one coordinate unit along each coordinate axis.\
\
File(s): [`_`](./)

### \[7\]
(D2) Define a function that draws a line connecting two shapes by finding the two closest
"contact points" and connecting them.\
\
File(s): [`_`](./)

### \[8\]
(D3) Add a notion of color to the simple graphics system. Three things can be colored: the
background, the inside of a closed shape, and the outlines of shapes.\
\
File(s): [`_`](./)

### \[9\]
(D2) Consider:
```C++
class Char_vec {
    int sz;
    char element[1];
public:
    static Char_vec* new_char_vec(int s);
    char& operator[](int i) { return element[i]; }
    // ...
};
```
Define `new_char_vec()` to allocate contiguous memory for a `Char_vec` object so that the elements can be indexed through element as shown. Under what circumstances does this trick cause serious problems?\
\
File(s): [`_`](./)

### \[10\]
(D2.5) Given classes `Circle`, `Square`, and `Triangle` derived from a class `Shape`, define a function `intersect()` that takes two Shape* arguments and calls suitable functions to determine if the two shapes overlap. It will be necessary to add suitable (virtual) functions to the classes to achieve this. Don't bother to write the code that checks for overlap; just make sure the right functions are called. This is commonly referred to as *double dispatch* or a *multi-method*.\
\
File(s): [`_`](./)

### \[11\]
(D5) Design and implement a library for writing event-driven simulations. Hint: `<task.h>`. However, that is an old program, and you can do better. There should be a class `task`. An object of class `task` should be able to save its state and to have that state restored (you might define `task::save()` and `task::restore()`) so that it can operate as a coroutine. Specific tasks can be defined as objects of classes derived from class `task`. The program to be executed by a task might be specified as a virtual function. It should be possible to pass arguments to a new task as arguments to its constructor(s). There should be a scheduler implementing a concept of virtual time. Provide a function `task::delay(long)` that "consumes" virtual time. Whether the scheduler is part of class task or separate will be one of the major design decisions. The tasks will need to communicate. Design a class `queue` for that. Devise a way for a task to wait for input from several queues. Handle run-time errors in a uniform way. How would you debug programs written using such a library?\
\
File(s): [`_`](./)

### \[12\]
(D2) Define interfaces for `Warrior`, `Monster`, and `Object` (that is a thing you can pick up, drop, use, etc.) classes for an adventure-style game.\
\
File(s): [`_`](./)

### \[13\]
(D1.5) Why is there both a `Point` and a `Dot` class in §X.21\[2\]? Under which circumstances would it be a good idea to augment the `Shape` classes with concrete versions of key classes such as `Line`?\
\
File(s): [`_`](./)

### \[14\]
(D3) Outline a different implementation strategy for the `Ival_box` example (§21.2) based on the idea that every class seen by an application is an interface containing a single pointer to the implementation. Thus, each "interface class" will be a handle to an "implementation class," and there will be an interface hierarchy and an implementation hierarchy. Write code fragments that are detailed enough to illustrate possible problems with type conversion. Consider ease of use, ease of programming, ease of reusing implementations and interfaces when adding a new concept to the hierarchy, ease of making changes to interfaces and implementations, and need for recompilation after change in the implementation.\
\
File(s): [`_`](./)

### \[15\]
(D2) Write a version of the `clone()` operation from §20.3.6 that can place its cloned object in an `Arena` (see §11.2.4) passed as an argument. Implement a simple `Arena` as a class derived from `Arena`.\
\
File(s): [`_`](./)
