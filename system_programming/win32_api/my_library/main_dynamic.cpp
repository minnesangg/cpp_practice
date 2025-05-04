#include <iostream>
#include <dlfcn.h>

typedef void (*HelloFunc)();
typedef int (*AddFunc)(int, int);

int main() {
    void* lib = dlopen("./libmylib.so", RTLD_LAZY);
    if (!lib) {
        std::cerr << "Error: " << dlerror() << std::endl;
        return 1;
    }

    HelloFunc Hello = (HelloFunc)dlsym(lib, "Hello");
    AddFunc Add = (AddFunc)dlsym(lib, "Add");

    if (Hello && Add) {
        Hello();
        std::cout << "2 + 3 = " << Add(2, 3) << std::endl;
    } else {
        std::cerr << "Func not founded!" << std::endl;
    }

    dlclose(lib);
    return 0;
}
