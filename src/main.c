#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1024
#define MAX_TOKENS 128

void print_banner(void) {
    printf("==============================\n");
    printf("       Shellforge\n");
    printf(" A Unix Style Shell written in C\n");
    printf("==============================\n");
}

int main(void) {
    char input[MAX_INPUT];
    char *tokens[MAX_TOKENS];

    print_banner();

    while (1) {
        printf("shellforge$ ");
        fflush(stdout);

        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        char *temp = input;
        while (isspace((unsigned char)*temp)) temp++;
        if (*temp == '\0') {
            continue;
        }

        if (strcmp(temp, "exit") == 0) {
            break;
        }

        int token_count = 0;
        char *token = strtok(input, " \t\r\n");
        while (token != NULL && token_count < MAX_TOKENS - 1) {
            tokens[token_count++] = token;
            token = strtok(NULL, " \t\r\n");
        }
        tokens[token_count] = NULL;

        printf("\n--------- TOKENS ---------\n");
        for (int i = 0; i < token_count; i++) {
            printf("%2d : %-8s %s\n", i, "WORD", tokens[i]);
        }
        printf("%2d : %-8s %s\n", token_count, "END", "END");
        printf("--------------------------\n\n");

        printf("========== PIPELINE ==========\n\n");
        printf("Command 1\n");
        printf("-----------------------------\n");
        printf("Arguments\n");
        for (int i = 0; i < token_count; i++) {
            printf("argv[%d] = %s\n", i, tokens[i]);
        }
        printf("Input      : None\n");
        printf("Output     : None\n");
        printf("Append     : No\n");
        printf("Background : No\n");
        printf("==============================\n\n");
    }

    return 0;
}
