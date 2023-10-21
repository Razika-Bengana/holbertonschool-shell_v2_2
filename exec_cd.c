#include "main.h"

void exec_cd(char **argv)
{
    char cwd[1024];

    char *oldpwd = my_getenv("PWD");

    if (argv[1] == NULL)
    {
        char *home = my_getenv("HOME");

        if (home != NULL)
        {
            chdir(home);
        }
    }
    else if (my_strcmp(argv[1], "-") == 0)
    {
        char *temp_oldpwd = my_getenv("OLDPWD");

        if (temp_oldpwd != NULL)
        {
            chdir(temp_oldpwd);
        }
    }
    else
    {
        chdir(argv[1]);
    }

    getcwd(cwd, sizeof(cwd));
    my_setenv("PWD", cwd, 1);
    my_setenv("OLDPWD", oldpwd, 1);
}
