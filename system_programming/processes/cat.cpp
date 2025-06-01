#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Using: cat <file1> [file2 ...]\n";
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        std::ifstream file(argv[i]);
        if (!file) {
            std::cerr << "Error oppening: " << argv[i] << "\n";
            continue;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << "\n";
        }

        file.close();
    }

    return 0;
}