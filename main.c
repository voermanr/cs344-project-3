#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "sys/wait.h"

#define BUFSIZE 2048
#define MAX_ARGUMENTS 256

char **tokenize_input(char *buf);

int main(void) {
    printf(":O < ");

    char *buf = 0;
    fgets(buf, BUFSIZE, stdin);
    printf("%s", buf);

    //char **argv;
    //argv = tokenize_input(buf);

    //printf("%s ", *argv);

    return 0;
}

char **tokenize_input(char *buf) {
    char **tok_arr = malloc(sizeof(char*) * MAX_ARGUMENTS);
    int i = 0;
    char *tok;
    for(; i < MAX_ARGUMENTS; ++i) {
        tok = strtok(buf, " ");
        tok_arr[i] = tok;
        if (tok == NULL) {
            return tok_arr;
        }
    }
    return NULL;
}
