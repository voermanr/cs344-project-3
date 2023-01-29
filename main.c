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
    int we_going = 1;
    while(we_going) {
        int argc = 0;
        char buf[MAX_LINE_CHARACTERS];
        char *argv[MAX_LINE_WORDS];

    for (int i = 0; i < MAX_LINE_WORDS; ++i) {

    }

    //printf("%s ", *argv);

        //Get me out of here!
        if (!strcmp(argv[0],"exit\n")) {
            we_going = 0;
        }
    }
    return 0;
}