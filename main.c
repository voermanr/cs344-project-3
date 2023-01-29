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

        // Print Prompt
        printf(PROMPT);

        // Get user input
        fgets(buf, MAX_LINE_CHARACTERS, stdin);

        if (DEBUG) printf("*honk*\t> %s", buf);

        // Where we tokenize into argv
        char *tok = strtok(buf, DELIMITERS);
        while (tok != NULL && argc < MAX_LINE_WORDS) {
            argv[argc++] = tok;
            tok = strtok(NULL, DELIMITERS);
        }
        argv[argc] = NULL;

        if (DEBUG) {
            printf("*honk*\t> arg[0]: %s", argv[0]);
            for (int i = 1; i < argc; ++i) {
                printf("\n\t\t  arg[%d]: %s", i, argv[i]);
            }
        }

        if (!strcmp(argv[0],"exit\n")) {
            we_going = 0;
        }
    }
    return 0;
}