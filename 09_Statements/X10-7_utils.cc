#include "X10-7.hh"

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>   // strerror
#include <cstdio>    // remove


namespace X10_7 {

int SettingsFromCommandLine(struct Settings &settings, int argc, char *argv[]) {
    if (argc < 1)
        throw std::invalid_argument("X10_7::SettingsFromCL: negative argc");
    if (argv == nullptr || argv[0] == nullptr)
        throw std::invalid_argument("X10_7::SettingsFromCL: nullptr argv");

    if (argc > 4)
        return 1;
    for (auto i {0}; i < argc; ++i) {
        if (argv[i][0] == '-') {
            if (i + 1 >= argc || argv[i + 1][0] == '-')
                return 1;
            switch (argv[i][1]) {
            case 'i':
                settings.in_place = true;
                settings.i_filename = argv[++i];
                break;
            case 'o':
                settings.o_filename = argv[++i];
                break;
            default:
                return 1;
            }
        } else if (i == 0) {
            settings.i_filename = argv[i];
        }
    }
    if (settings.in_place)
        settings.o_filename = settings.i_filename + ".tmp";
    return 0;
}


void RemoveCPPComments(std::istream &is, std::ostream &os) {
    std::string line;
    std::string rstr_delim;
    TextState state { TextState::dflt };
    bool mlc_exit {false};  // handles edge case of *//*
    while (std::getline(is, line)) {
        for (std::size_t i {0}; i < line.size(); ++i) {
            switch (line[i]) {
            case '/':
                if (state == TextState::dflt) {
                    if (line[i + 1] == '/') {
                        state = TextState::slc;
                    }
                    if (line[i + 1] == '*') {
                        state = TextState::mlc;
                        ++i;
                    }
                }
                break;
            case '*':
                if (state == TextState::mlc && line[i + 1] == '/') {
                    state = TextState::dflt;
                    ++i;
                    mlc_exit = true;
                }
                break;
            case '\'':
                if (i == 0 ||
                    (i == 1 && line[i - 1] != '\\') ||
                    (line[i - 1] != '\\' || line[i - 2] == '\\')) {
                    if (state == TextState::dflt)
                        state = TextState::chr;
                    else if (state == TextState::chr)
                        state = TextState::dflt;
                }
                break;
            case 'R':
                if (state == TextState::dflt && line[i + 1] == '"') {
                    std::size_t j {i + 2};
                    // g++ raw string delimter max 16 chars
                    for (; j - i < 18 && line[j] != '('; ++j)
                        rstr_delim += line[j];
                    if (line[j] == '(') {
                        state = TextState::rstr;
                    } else {  // ignore invalid code
                        rstr_delim = "";
                    }
                }
                break;
            case '"':
                if (state == TextState::rstr) {
                    std::size_t j {i - 1};
                    for (std::size_t k {
                            rstr_delim.size() ? rstr_delim.size() - 1 : 0};
                         line[j] != ')' && line[j] == rstr_delim[k];
                         --j, --k) {}
                    if (line[j] == ')') {
                        state = TextState::dflt;
                        rstr_delim = "";
                    }
                } else if (i == 0 ||
                           (i == 1 && line[i - 1] != '\\') ||
                           (line[i - 1] != '\\' || line[i - 2] == '\\')) {
                    if (state == TextState::dflt)
                        state = TextState::str;
                    else if (state == TextState::str)
                        state = TextState::dflt;
                }
                break;
            default:
                break;
            }
            // single line comment tuncates line
            if (state == TextState::slc) {
                state = TextState::dflt;
                break;
            }
            if (state != TextState::mlc && !mlc_exit)
                os << line[i];
            if (mlc_exit)
                mlc_exit = false;
        }
        if (state != TextState::mlc)
            os << std::endl;
        // open string or char literal is invalid code, not editing out
        if (state == TextState::chr || state == TextState::str)
            state = TextState::dflt;
    }
}


// C++17 introduces std::fileystem::copy_file to make this easier
void OverwriteFromTempFile(std::string &i_filename, std::string &o_filename) {
    std::ifstream ifs {i_filename};
    if (!ifs.good() && errno) {
        throw std::runtime_error("X10-7::OverwriteFromTempFile: "
                                 "Failure to open input file '" +
                                 i_filename +
                                 "': " + strerror(errno));
    }
    std::ofstream ofs {o_filename};
    if (!ofs.good() && errno) {
        throw std::runtime_error("X10-7::OverwriteFromTempFile: "
                                 "Failure to open output file '" +
                                 o_filename +
                                 "': " + strerror(errno));
    }
    std::string line;
    while (std::getline(ifs, line))
        ofs << line << std::endl;
    ifs.close();   // ofs implicitly closed
    std::remove(i_filename.c_str());
    if (errno) {
        throw std::runtime_error("Failure to delete input file '" +
                                 i_filename +
                                 "': " + strerror(errno));
    }
}

}  // namespace X10_7
