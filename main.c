#include "main.h"

int main(int ac, char **argv)
{
    char *prompt = "(hsh) $ ";
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    char *token;
    int num_tokens = 0;
    int i;
    (void)ac;
    (void)argv;

    while (1)
    {
        if (isatty(STDIN_FILENO))
        {
            printf("%s", prompt);
        }

        nchars_read = getline(&lineptr, &n, stdin);

        if (nchars_read == -1)
        {
            printf("Exiting shell....\n");
            break;
        }

        char *lineptr_copy = my_strdup(lineptr);

        if (lineptr_copy == NULL)
        {
            perror("Duplication error");
            exit(EXIT_FAILURE);
        }

        token = strtok(lineptr, " \n");

        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, " \n");
        }
        num_tokens++;

        char **cmd_argv = malloc(sizeof(char *) * num_tokens);

        if (cmd_argv == NULL)
        {
            perror("Allocation error");
            exit(EXIT_FAILURE);
        }

        token = strtok(lineptr_copy, " \n");

        for (i = 0; token != NULL; i++)
        {
            cmd_argv[i] = my_strdup(token);

            if (cmd_argv[i] == NULL)
            {
                perror("Duplication error");
                exit(EXIT_FAILURE);
            }

            token = strtok(NULL, " \n");
        }
        cmd_argv[i] = NULL;

        if (my_strcmp(cmd_argv[0], "cd") == 0)
        {
            exec_cd(cmd_argv);
        }
        else
        {
            exec_cmd(cmd_argv);
        }

        for (i = 0; cmd_argv[i] != NULL; i++)
        {
            free(cmd_argv[i]);
        }
        free(cmd_argv);
        free(lineptr_copy);

        num_tokens = 0;
    }
    free(lineptr);
    return (0);
}
