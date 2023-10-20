#include "main.h"

void exec_cd(char **argv)
{
    if (argv[1] == NULL)
    {
        char *home = my_getenv("HOME");
        if (home != NULL)
        {
            if (chdir(home) != 0)
            {
                perror("cd");
            }
        }
        else
        {
            fprintf(stderr, "cd: HOME environment variable not set.\n");
        }
    }
    else
    {
        if (chdir(argv[1]) != 0)
        {
            perror("cd");
        }
    }
}