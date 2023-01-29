#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "sys/wait.h"

#define MAX_LINE_CHARACTERS 2048
#define MAX_LINE_WORDS 256

#define DELIMITERS " "
#define PROMPT "*<@:) \t< "

#ifndef DEBUG
#define DEBUG 0
#endif

int main(void) {
    printf("*<@:) < ");

    char buf[MAX_LINE_CHARACTERS];
    fgets(buf, MAX_LINE_CHARACTERS, stdin);
    printf("%s", buf);

    char *argv[MAX_LINE_WORDS];

    for (int i = 0; i < MAX_LINE_WORDS; ++i) {

    }

    //printf("%s ", *argv);

    return 0;
}