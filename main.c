#include "main.h"

ssize_t getline(char **pString, size_t *pInt, FILE *pIobuf);

int main(int ac, char **argv)
{
    char *prompt = "hsh $ ";
    char *lineptr = NULL, *lineptr_copy = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i;

    /* Void variables */
    (void)ac;

    while (1)
    {
        printf("%s", prompt);
        nchars_read = getline(&lineptr, &n, stdin);
        /* Check if the getline function failed or reached EOF, or if the user use CTRL + D */
        if (nchars_read == -1)
        {
            printf("Exiting shell....\n");
            return (-1);
        }

        lineptr_copy = malloc(sizeof(char) * nchars_read);
        if (lineptr_copy == NULL)
        {
            perror("tsh: memory allocation error");
            break;
        }
        my_strcpy(lineptr_copy, lineptr);

        token = strtok(lineptr, delim);

        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;

        argv = malloc(sizeof(char *) * num_tokens);

        token = strtok(lineptr_copy, delim);

        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * my_strlen(token));
            my_strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        exec_cmd(argv);

        for (i = 0; argv[i] != NULL; i++)
        {
            free(argv[i]);
        }
        free(argv);
        free(lineptr_copy);

        num_tokens = 0;
    }

    free(lineptr);

    return (0);
}