#include "main.h"

extern char **environ;

char *my_getenv(const char *name)
{
    int i;
    size_t name_len;

    if (name == NULL)
    {
        return (NULL);
    }
    name_len = my_strlen(name);

    for (i = 0; environ[i] != NULL; i++)
    {
        if (my_strncmp(environ[i], name, name_len) == 0)
        {
            if (environ[i][name_len] == '=')
            {
                return &environ[i][name_len + 1];
            }
        }
    }

    return (NULL);
}

