#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>

class Replacer {
private:
    std::string filename;
    std::string s1;
    std::string s2;

public:
    Replacer(const std::string& filename, const std::string& s1, const std::string& s2);
    bool replaceContent();
};

#endif
