#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "sys/wait.h"

#define MAX_LINE_CHARACTERS 2048
#define MAX_LINE_WORDS 128

#define DELIMITERS " \n"
#define PROMPT "*<@:) \t< "

#ifndef DEBUG
#define DEBUG 0
#endif

#define INTRO "\tWELCOME TO MUSH: \nA SHELL FOR CLOWNS BY CLOWNS\n\n\t\tLead Clown: Ross V\n\n\n"

int build_argv(int argc, char *buf, char **argv);

int tokenize_string(char *buf, char **argv);

int main(void) {
    int we_going = 1;

    printf(INTRO);

    while(we_going) {
        int argc = 0;
        char buf[MAX_LINE_CHARACTERS];
        char *argv[MAX_LINE_WORDS];

        char *pwd = getcwd(NULL,0);


        printf("%s %s", pwd, PROMPT); // Print Prompt
        free(pwd);


        fgets(buf, MAX_LINE_CHARACTERS, stdin); // Get user input

        if (DEBUG) printf("*honk*\t> %s", buf);

        build_argv(argc, buf, argv);


        if (DEBUG) {
            printf("*honk*\t> arg[0]: %s", argv[0]);
            for (int i = 1; i < argc; ++i) {
                printf("\n\t\t  arg[%d]: %s", i, argv[i]);
            }
        } // Print out argv during debug

        if (!strcmp(argv[0],"exit")) {
            exit(0);
        }

        else if (!strcmp(argv[0],"cd")) {
            int z = chdir(argv[1]);
            if (z == -1) {
                perror(argv[1]);
                exit(1);
            } else continue;
        }

        else {
            pid_t the_baby = fork();
            if (the_baby && execvp(argv[0], argv)) {
                perror(argv[0]);
                exit(1);
            } else wait(&the_baby);
        }
    }
}

int build_argv(int argc, char *buf, char **argv) {
    argc = tokenize_string(buf, argv);
    argv[argc] = NULL;
    return 0;
}

int tokenize_string(char *buf, char **argv) {
    int num_tokens = 0;

    char *tok = strtok(buf, DELIMITERS);
    while (tok != NULL && num_tokens < MAX_LINE_WORDS) {
        argv[num_tokens++] = tok;
        tok = strtok(NULL, DELIMITERS);
    }
    return num_tokens;
}
