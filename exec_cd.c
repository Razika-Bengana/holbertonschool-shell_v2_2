#include "main.h"

void exec_cd(char **argv)
{
    char cwd[1024];
    char *oldpwd = my_getenv("OLDPWD");
    char *home = my_getenv("HOME");

    if (argv[1] == NULL)
    {
        if (home != NULL)
        {
            if(chdir(home) != 0)
            {
                perror("cd");
            }
        }
        else
        {
            fprintf(stderr, "cd: HOME not set\n");
        }
    }
    else if (my_strcmp(argv[1], "-") == 0)
    {
        if (oldpwd != NULL)
        {
            if(chdir(oldpwd) != 0)
            {
                perror("cd");
            }
        }
        else
        {
            fprintf(stderr, "cd: OLDPWD not set\n");
        }
    }
    else
    {
        if(chdir(argv[1]) != 0)
        {
            perror("cd");
        }
    }

    getcwd(cwd, sizeof(cwd));
    my_setenv("PWD", cwd, 1);

    if (oldpwd != NULL)
    {
        my_setenv("OLDPWD", oldpwd, 1);
    }
}
