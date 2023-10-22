#include "main.h"

void exec_cd(char **argv)
{
    char cwd[1024];
    char *oldpwd = my_getenv("OLDPWD");
    char *home = my_getenv("HOME");
    char *new_oldpwd = NULL;

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        new_oldpwd = my_strdup(cwd);
    }
    else
    {
        perror("getcwd");
        return;
    }

    if (argv[1] == NULL)
    {
        if (home != NULL)
        {
            if(chdir(home) == 0)
            {
                my_setenv("OLDPWD", new_oldpwd, 1);
            }
            else
            {
                perror("cd");
            }
        }
    }
    else if (my_strcmp(argv[1], "-") == 0)
    {
        if (oldpwd != NULL)
        {
            if(chdir(oldpwd) == 0)
            {
                printf("%s\n", oldpwd);
                my_setenv("OLDPWD", new_oldpwd, 1);

                if (getcwd(cwd, sizeof(cwd)) != NULL)
                {
                    my_setenv("PWD", cwd, 1);
                }
                else
                {
                    perror("getcwd");
                }
            }
            else
            {
                perror("cd");
            }
        }
    }
    else
    {
        if(chdir(argv[1]) == 0)
        {
            my_setenv("OLDPWD", new_oldpwd, 1);
        }
        else
        {
            fprintf(stderr, "./hsh: 1: cd: can't cd to %s\n", argv[1]);
        }
    }

    if (new_oldpwd)
    {
        free(new_oldpwd);
    }

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        my_setenv("PWD", cwd, 1);
    }
    else
    {
        perror("getcwd");
    }
}