#include <iostream>
#include <sstream>
#include <string>
#include <map>


long double ParseNameValuePairs(std::istream &is,
                                std::map<std::string, double> &values_by_name) {
    std::string pair_s;
    std::string name_s;
    std::string name;
    std::istringstream pair_iss;
    std::istringstream name_iss;
    double value;
    long double total {0};
    char c;

    for (int i {0}; std::getline(is, pair_s, ')');) {
        pair_iss.clear();  // clears eof flag from last read
        pair_iss.str(pair_s);
        if (!(pair_iss >> std::ws >> c) || c != '(' ||
            !std::getline(pair_iss, name_s, ',')) {
            is.setstate(std::ios_base::failbit);
            break;
        }
        name_iss.clear();
        name_iss.str(name_s);
        if (!(name_iss >> name >> std::ws) || !name_iss.eof() ||
            !(pair_iss >> value >> std::ws) || !pair_iss.eof()) {
            is.setstate(std::ios_base::failbit);
            break;
        }
        values_by_name[name] = value;
        ++i;
        total += value;
        std::cout << "New entry: (\"" << name << "\", " << value <<
            ")\n\t\t\tCurrent total of values: " << total <<
            "  Current mean value: " << total / i << std::endl;
    }

    return total;
}


int main() {
    std::map<std::string, double> values_by_name;

    long double total {ParseNameValuePairs(std::cin, values_by_name)};
    if (!std::cin.eof())
        return 1;

    std::cout << "\nFinal total of values: " << total <<
        "  Final mean of values: " << total / values_by_name.size() << std::endl;
}
