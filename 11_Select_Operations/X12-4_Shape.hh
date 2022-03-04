#ifndef X12_4_SHAPE_HH
#define X12_4_SHAPE_HH


// `class Shape` is introduced only as an example in 3.2.4 to illustrate class
//    hierarchies. However, exercise X12-4 presumes that it is already available
//    to the student. Exercises in chapter 20/X21 seem to have the student
//    developing their own `Shape` and subclassses; instead what follows is
//    simply an annotated adaptation of the 3.2.4 and 3.3.4 example code.


namespace X12_4 {


// Cannot use default member initializers here, as it prevents later use of
//   aggregate initialization, see:
//   - https://en.cppreference.com/w/cpp/language/aggregate_initialization
struct Point {
    int x; // {0};
    int y; // {0};
};


class Shape {
public:
    // Given that Shape is only an interface to derived classes, we can
    //   prohibit the default definitions of its copy and move operations:
    Shape(const Shape &) = delete;              // copy construction
    Shape &operator=(const Shape &) = delete;   // copy initialization

    Shape(const Shape &&) = delete;             // move construction
    Shape &operator=(const Shape &&) = delete;  // move initialization

    // `vitrual...= 0` -> pure virtual, must be defined by derived class
    // const function suffix -> may not alter member variables
    virtual Point center() const = 0;
    virtual void move(Point to) = 0;

//  virtual void draw() const = 0;
//  virtual rotate(int angle) = 0;

    // not pure virtual, may be overloaded by derived class, but not required
    virtual ~Shape() {}

    // making constructor of interface class protected prevents instantiation of
    //   raw `Shape`s (constructor cannot be declared as virtual), see:
    //   - https://stackoverflow.com/questions/6272445
protected:
    Shape() {}
};


class Circle : public Shape {
public:
    Circle(Point p, unsigned int _r) : c{p}, r{_r} {}

    Point center() const { return c; }
    void move(Point new_c) { c = new_c; }

//  void draw() const;
//  void rotate(int angle) {}
private:
    Point c;         // center
    unsigned int r;  // radius
};


}  // namespace X12_4


#endif  // X12_4_SHAPE_HH
