#include <iostream>
#include <cctype>

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            for (char c : arg) {
                std::cout << (char)std::toupper(c);
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
