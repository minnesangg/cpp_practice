#include <stdio.h>

extern void PrintStrings(const char*, const char*);
extern void PrintMsg(const char*);
extern void ConsolePrompt();

int main() {
    PrintMsg("Hello from ConsoleIO!");
    PrintStrings("This is", "example.");
    ConsolePrompt();
    return 0;
}
