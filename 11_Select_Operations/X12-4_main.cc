#include <iostream>
#include <vector>
#include "X12-4_Shape.hh"


namespace X12_4 {


// Using rvalue to generalize a function pointer as parameter to another
//   function, see:
//   - https://stackoverflow.com/q/40844622/
template<typename T, typename ...Types>
void Apply(std::vector<Shape *> &v, T &&f, Types ...f_args) {
    for (auto &x : v)
        f(x, f_args...);
}
// Alternatives could be:
//   * pass `void *` that can be cast to appropriate function pointer
//       (C-like, not idiomatic C++)
//   * writing several overloads for `apply()` to anticipate expected function
//       pointer types (less flexible, more code to write)
//   * use std::function<> and std::bind (reportedly greater overhead,) see:
//       - https://stackoverflow.com/a/6412943/
//       - https://stackoverflow.com/q/40844622/
//       - https://stackoverflow.com/a/28747100/


void MoveRight_Func(Shape *sp, int i) {
    if (sp != nullptr) {
        Point new_ctr { sp->center() };
        new_ctr.x += i;
        sp->move(new_ctr);
    }
}


class MoveRight_FuncObj {
public:
    MoveRight_FuncObj(const int &v) :val{v} {}
    void operator()(Shape *sp) {
        if (sp != nullptr) {
            Point new_ctr { sp->center() };
            new_ctr.x += val;
            sp->move(new_ctr);
        }
    }
private:
    const int val;
};


std::ostream &operator<<(std::ostream &os, const Point &p) {
    return os << p.x << ", " << p.y;
}


}  // namespace X12_4



int main() {
    std::vector<X12_4::Shape *> v;
    v.push_back(new X12_4::Circle {{3, 3}, 5});
    v.push_back(new X12_4::Circle {{9, 9}, 5});

    std::cout << v[0]->center() << std::endl;
    std::cout << v[1]->center() << std::endl;

    // using function
    X12_4::Apply(v, X12_4::MoveRight_Func, 10);

    std::cout << v[0]->center() << std::endl;
    std::cout << v[1]->center() << std::endl;

    // using function object / "functor"
    X12_4::MoveRight_FuncObj MoveRight_10 {10};
    X12_4::Apply(v, MoveRight_10);

    std::cout << v[0]->center() << std::endl;
    std::cout << v[1]->center() << std::endl;

    // using lambda with no capture, arg value in body
    X12_4::Apply(v, [](X12_4::Shape *sp) {
                        if (sp != nullptr) {
                            X12_4::Point new_ctr { sp->center() };
                            new_ctr.x += 10;
                            sp->move(new_ctr);
                        }
                    });

    std::cout << v[0]->center() << std::endl;
    std::cout << v[1]->center() << std::endl;

    int i {10};
    // using lambda with implicit capture (of all local) by reference
    X12_4::Apply(v, [&](X12_4::Shape *sp) {
                        if (sp != nullptr) {
                            X12_4::Point new_ctr { sp->center() };
                            new_ctr.x += i;
                            sp->move(new_ctr);
                        }
                    });

    std::cout << v[0]->center() << std::endl;
    std::cout << v[1]->center() << std::endl;

    // using lambda with explicit capture by reference
    X12_4::Apply(v, [&i](X12_4::Shape *sp) {
                        if (sp != nullptr) {
                            X12_4::Point new_ctr { sp->center() };
                            new_ctr.x += i;
                            sp->move(new_ctr);
                        }
                    });

    std::cout << v[0]->center() << std::endl;
    std::cout << v[1]->center() << std::endl;

    for (auto &x : v)
        delete x;
}
