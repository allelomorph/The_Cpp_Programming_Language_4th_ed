#ifndef X10_7_HH
#define X10_7_HH

#include <iostream>
#include <string>


namespace X10_7 {

// default, single line comment, multi line comment, character literal,
//   string literal, raw string literal
enum class TextState { dflt, slc, mlc, chr, str, rstr };

/**
 * struct Settings - input and output file setting info for exercise X10-7
 *
 * @in_place: if true, modify input file in place
 * @i_filename: input filename
 * @o_filename: output filename
 */
struct Settings {
    bool in_place {false};
    std::string i_filename;
    std::string o_filename;
};

int SettingsFromCommandLine(struct Settings &settings, int argc, char *argv[]);

void OverwriteFromTempFile(std::string &i_filename, std::string &o_filename);

void RemoveCPPComments(std::istream &is, std::ostream &os);

}  // namespace X10_7

#endif  // X10_7_HH
