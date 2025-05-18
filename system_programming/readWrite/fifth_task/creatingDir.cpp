#include <iostream>
#include <sys/stat.h>   
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>     
#include <cstring>     
#include <errno.h>

bool copyFile(const char* src, const char* dest) {
    const size_t bufSize = 4096;
    char buffer[bufSize];

    int in = open(src, O_RDONLY);
    if (in < 0) {
        std::cerr << "Error opening source file: " << strerror(errno) << "\n";
        return false;
    }

    int out = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out < 0) {
        std::cerr << "Error opening destination file: " << strerror(errno) << "\n";
        close(in);
        return false;
    }

    ssize_t bytesRead;
    while ((bytesRead = read(in, buffer, bufSize)) > 0) {
        ssize_t bytesWritten = write(out, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            std::cerr << "Write error: " << strerror(errno) << "\n";
            close(in);
            close(out);
            return false;
        }
    }

    if (bytesRead < 0) {
        std::cerr << "Read error: " << strerror(errno) << "\n";
    }

    close(in);
    close(out);

    return bytesRead >= 0;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <base_directory> <new_subdir_name> <file_to_copy>\n";
        return 1;
    }

    const char* baseDir = argv[1];
    const char* subDir = argv[2];
    const char* srcFile = argv[3];

    std::string newDir = std::string(baseDir) + "/" + subDir;

    if (mkdir(newDir.c_str(), 0755) != 0) {
        if (errno != EEXIST) {
            std::cerr << "Error creating directory: " << strerror(errno) << "\n";
            return 1;
        } else {
            std::cout << "Directory already exists, continuing...\n";
        }
    } else {
        std::cout << "Directory created: " << newDir << "\n";
    }

    std::string destFile = newDir + "/" + srcFile;

    size_t pos = std::string(srcFile).find_last_of('/');
    std::string filename = (pos == std::string::npos) ? srcFile : std::string(srcFile).substr(pos + 1);
    destFile = newDir + "/" + filename;

    if (!copyFile(srcFile, destFile.c_str())) {
        std::cerr << "Failed to copy file.\n";
        return 1;
    }

    std::cout << "File copied to " << destFile << "\n";

    return 0;
}
