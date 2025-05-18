#include <iostream>
#include <dirent.h>
#include <cstring>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: ./search_file <directory> <filename>\n";
        return 1;
    }
    const char* dir_path = argv[1];
    const char* file_to_find = argv[2];

    DIR* dir = opendir(dir_path);
    if (!dir) {
        std::cerr << "Cannot open directory\n";
        return 1;
    }

    struct dirent* entry;
    bool found = false;
    while ((entry = readdir(dir)) != nullptr) {
        if (strcmp(entry->d_name, file_to_find) == 0) {
            std::cout << "Found file: " << entry->d_name << " in " << dir_path << std::endl;
            found = true;
            break;
        }
    }

    closedir(dir);

    if (!found) {
        std::cout << "File not found\n";
    }

    return 0;
}