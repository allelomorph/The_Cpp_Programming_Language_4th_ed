/**
 * 3.2.1.1 An Arithmetic Type
 */

class complex (
	double re, im;  // representation
public:
	// using braces for member inits: https://stackoverflow.com/a/15396154
	complex(double r, double i) :re{r}, im{i} {}  // two scalars
	complex(double r) :re{r}, im{0} {}  // one scalar
	complex() :re{0}, im{0} {}  // default constructor

	// const function suffix declares that it will not modify the object that calls it
	//    -> or more broadly that it can be called on const objects
	// functions defined in the class definition are inlined by default, improving efficiency
	double real() const { return re; }
	void real(double d) { re = d; }
	double imag() const { return im; }
	void imag(double d) { im = d; }

	// `this` is the object on which a non-static member function is called...
	// not sure why it returns a reference, but no reference is created...
	complex &operator+=(complex z) { re += z.re; im += z.im; return *this; }
	complex &operator-=(complex z) { re -= z.re; im -= z.im; return *this; }
}
