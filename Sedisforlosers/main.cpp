#include <iostream>
#include <fstream>
#include <string>

int replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    if (s1.empty()) {
        std::cerr << "Error: string s1 cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: cannot open input file '" << filename << "'" << std::endl;
        return 1;
    }

    std::ofstream outfile(filename + ".replace");
    if (!outfile) {
        std::cerr << "Error: cannot create output file '" << filename << ".replace'" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::string result;
        size_t pos = 0;
        size_t found;

        while ((found = line.find(s1, pos)) != std::string::npos) {
            result += line.substr(pos, found - pos);
            result += s2;
            pos = found + s1.length();
        }
        result += line.substr(pos);

        outfile << result << "\n";
    }

    infile.close();
    outfile.close();
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    return replaceInFile(filename, s1, s2);
}
