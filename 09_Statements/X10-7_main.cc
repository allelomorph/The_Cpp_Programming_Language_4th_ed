#include "X10-7.hh"

#include <iostream>
#include <fstream>
#include <cstring>   // strerror


int main(int argc, char *argv[]) {
    using namespace X10_7;
    struct Settings settings;
    if (argc > 1 &&
        SettingsFromCommandLine(settings, argc - 1, argv + 1) != 0) {
        std::cerr << "Usage: " << argv[0] <<
            " [-i] [input file] [-o output_file]" << std::endl;
        return 1;
    }
    std::ifstream ifs;
    if (settings.i_filename != "") {
        ifs.open(settings.i_filename);
        if (errno) {
            throw std::runtime_error("Failure to open input file '" +
                                     settings.i_filename +
                                     "': " + strerror(errno));
        }
    }
    std::ofstream ofs;
    if (settings.o_filename != "") {
        ofs.open(settings.o_filename);
        if (errno) {
            throw std::runtime_error("Failure to open output file '" +
                                     settings.o_filename +
                                     "': " + strerror(errno));
        }
    }
    RemoveCPPComments(ifs.is_open() ? ifs : std::cin,
                      ofs.is_open() ? ofs : std::cout);
    if (settings.in_place) {
        ifs.close();
        ofs.close();
        OverwriteFromTempFile(settings.o_filename, settings.i_filename);
    }
}
