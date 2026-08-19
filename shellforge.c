#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 256
#define MAX_TOKENS 50

void lexer(char *input)
{
    char tokens[MAX_TOKENS][MAX_INPUT];
    int count = 0;
    int i = 0;

    while (input[i] != '\0' && input[i] != '\n') {

        while (isspace((unsigned char)input[i]))
            i++;

        if (input[i] == '\0' || input[i] == '\n')
            break;

        /* Handle double quotes */
        if (input[i] == '"') {
            i++;

            int start = i;
            int j = 0;

            while (input[i] != '"' &&
                   input[i] != '\0' &&
                   input[i] != '\n') {
                tokens[count][j++] = input[i++];
            }

            tokens[count][j] = '\0';

            if (input[i] != '"') {
                printf("\nLexer Error : Unterminated double quote\n");
                return;
            }

            i++;
            count++;
        }

        /* Handle single quotes */
        else if (input[i] == '\'') {
            i++;

            int j = 0;

            while (input[i] != '\'' &&
                   input[i] != '\0' &&
                   input[i] != '\n') {
                tokens[count][j++] = input[i++];
            }

            tokens[count][j] = '\0';

            if (input[i] == '\'')
                i++;

            count++;
        }

        /* Normal word */
        else {
            int j = 0;

            while (input[i] != '\0' &&
                   input[i] != '\n' &&
                   !isspace((unsigned char)input[i])) {
                tokens[count][j++] = input[i++];
            }

            tokens[count][j] = '\0';
            count++;
        }
    }

    printf("\n------------ TOKENS ------------\n");

    for (int k = 0; k < count; k++) {
        printf("%d : WORD       %s\n", k, tokens[k]);
    }

    printf("%d : END        END\n", count);

    printf("--------------------------------\n");
}

int main()
{
    char input[MAX_INPUT];

    printf("====================================\n");
    printf("             Shellforge\n");
    printf("     A Unix Style Shell written in C\n");
    printf("====================================\n");

    while (1) {

        printf("shellforge$ ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        if (strcmp(input, "exit\n") == 0)
            break;

        lexer(input);
    }

    return 0;
}
