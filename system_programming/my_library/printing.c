#include <stdio.h>

void PrintStrings(const char* a, const char* b) {
    printf("%s %s\n", a, b);
}

void PrintMsg(const char* msg) {
    puts(msg);
}

void ConsolePrompt() {
    char buf[128];
    printf("Input: ");
    fgets(buf, sizeof(buf), stdin);
    printf("Your text: %s", buf);
}
