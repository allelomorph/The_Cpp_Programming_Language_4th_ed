#include "X11-11_TokenStream.hh"
#include <iostream>


namespace X11_11 {


void calculate() {
    while (true) {
        ts.get();
        if (ts.current().kind == Kind::end)
            break;
        if (ts.current().kind == Kind::print)
            continue;
        std::cout << expr(false) << std::endl;
    }
}


}  // namespace X11_11


int main(){
    X11_11::name_table["pi"] = 3.1415926535897932385;
    X11_11::name_table["e"]  = 2.7182818284590452354;

    X11_11::calculate();
#ifdef DEBUG
    for (auto &x : X11_11::name_table)
        std::cout << x.first << ' ' << x.second << std::endl;
#endif
    return X11_11::error_ct;
}
