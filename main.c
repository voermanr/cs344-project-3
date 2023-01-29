#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "sys/wait.h"

#define MAX_LINE_CHARACTERS 2048
#define MAX_LINE_WORDS 256

#define DELIMITERS " \n"
#define PROMPT "*<@:) \t< "

#ifndef DEBUG
#define DEBUG 0
#endif

#define INTRO "\tWELCOME TO MUSH: \nA SHELL FOR A CLOWNS BY CLOWNS\n\n\t\tLead Clown: Ross V\n\n\n"

int build_argv(int argc, char *buf, char **argv);

int main(void) {
    int we_going = 1;
    printf(INTRO);
    while(we_going) {
        int argc = 0;
        char buf[MAX_LINE_CHARACTERS];
        char *argv[MAX_LINE_WORDS];


        printf(PROMPT); // Print Prompt


        fgets(buf, MAX_LINE_CHARACTERS, stdin); // Get user input

        if (DEBUG) printf("*honk*\t> %s", buf);

        build_argv(argc, buf, argv);


        if (DEBUG) {
            printf("*honk*\t> arg[0]: %s", argv[0]);
            for (int i = 1; i < argc; ++i) {
                printf("\n\t\t  arg[%d]: %s", i, argv[i]);
            }
        } // Print out argv during debug

        // PART 1-6
        execvp(argv[0],argv);

        if (!strcmp(argv[0],"exit\n")) {
            we_going = 0;
        } //Get me out of here!
    }
    return 0;
}

int build_argv(int argc, char *buf, char **argv) {
    char *tok = strtok(buf, DELIMITERS);
    while (tok != NULL && argc < MAX_LINE_WORDS) {
        argv[argc++] = tok;
        tok = strtok(NULL, DELIMITERS);
    }
    argv[argc] = NULL;
    return 0;
}
