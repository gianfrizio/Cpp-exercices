#include "Replacer.hpp"
#include <fstream>
#include <iostream>

Replacer::Replacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {}

bool Replacer::replaceContent() {
    if (s1.empty()) {
        std::cerr << "Error: s1 must not be empty\n";
        return false;
    }

    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Cannot open input file\n";
        return false;
    }

    std::string outfilename = filename + ".replace";
    std::ofstream outfile(outfilename);
    if (!outfile) {
        std::cerr << "Error: Cannot open output file\n";
        return false;
    }

    std::string line;
    while (std::getline(infile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outfile << line << '\n';
    }

    return true;
}
