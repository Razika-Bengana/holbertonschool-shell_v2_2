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
            return;
        }
    }
    else if (my_strcmp(argv[1], "-") == 0)
    {
        char *oldpwd = my_getenv("OLDPWD");

        if (oldpwd != NULL)
        {
            if (chdir(oldpwd) != 0)
            {
                perror("cd");
            }
        }
        else
        {
            return;
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
