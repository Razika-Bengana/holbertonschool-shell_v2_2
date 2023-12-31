#include "main.h"

extern char **environ;

char *my_getenv(const char *name)
{
    int i = 0;
    size_t name_len = my_strlen(name);

    while (environ[i] != NULL)
    {
        if (my_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
        {
            return &environ[i][name_len + 1];
        }
        i++;
    }
    return (NULL);
}

