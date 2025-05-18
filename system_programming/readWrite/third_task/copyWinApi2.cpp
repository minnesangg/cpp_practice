#include <windows.h>
#include <iostream>

int main(int argc, char* argv[]){

    if (argc != 3) {
        std::cout << "Использование: copyfile.exe <исходный файл> <целевой файл>\n";
        return 1;
    }

    const char* source = argv[1];
    const char* dest = argv[2];

    BOOL result = CopyFileA(source, dest, FALSE);

    if(result){
        std::cout << "File copied!\n";
    } else {
        std::cout << "Error copying file. Error code: " << GetLastError() << std::endl;
    }

    return 0;
}