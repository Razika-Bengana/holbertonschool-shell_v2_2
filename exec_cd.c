#include "main.h"

void exec_cd(char **argv)
{
    char cwd[1024];
    char *oldpwd = my_getenv("OLDPWD");
    char *pwd = my_getenv("PWD");

    if (argv[1] == NULL)
    {
        char *home = my_getenv("HOME");
        if (home != NULL)
        {
            chdir(home);
        }
        getcwd(cwd, sizeof(cwd));
        my_setenv("PWD", cwd, 1);
        my_setenv("OLDPWD", pwd, 1);
    }
    else if (my_strcmp(argv[1], "-") == 0)
    {
        if (oldpwd != NULL)
        {
            chdir(oldpwd);
            printf("%s\n", oldpwd);
        }
        else
        {
            printf("%s\n", pwd);
        }
        getcwd(cwd, sizeof(cwd));
        my_setenv("PWD", cwd, 1);
        my_setenv("OLDPWD", pwd, 1);
    }
    else
    {
        chdir(argv[1]);
        getcwd(cwd, sizeof(cwd));
        my_setenv("PWD", cwd, 1);
        my_setenv("OLDPWD", pwd, 1);
    }
}
