#include "main.h"

extern char **environ;

int my_setenv(const char *name, const char *value, int overwrite)
{
    int i, env_len = 0;
    size_t name_len, value_len;
    char **new_environ;

    if (name == NULL || value == NULL || my_strchr(name, '=') != NULL)
    {
        return (-1);
    }

    name_len = my_strlen(name);
    value_len = my_strlen(value);

    while (environ[env_len] != NULL)
    {
        env_len++;
    }

    for (i = 0; i < env_len; i++)
    {
        if (my_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
        {
            if (overwrite)
            {
                char *new_value = malloc(name_len + value_len + 2);
                if (new_value == NULL)
                {
                    return -1;
                }
                sprintf(new_value, "%s=%s", name, value);
                free(environ[i]);
                environ[i] = new_value;
            }
            return (0);
        }
    }

    new_environ = malloc((env_len + 2) * sizeof(char *));
    if (new_environ == NULL)
    {
        return (-1);
    }

    for (i = 0; i < env_len; i++)
    {
        new_environ[i] = environ[i];
    }

    new_environ[env_len] = malloc(name_len + value_len + 2);
    if (new_environ[env_len] == NULL)
    {
        free(new_environ);
        return (-1);
    }

    sprintf(new_environ[env_len], "%s=%s", name, value);
    new_environ[env_len + 1] = NULL;

    if (environ != NULL)
    {
        free(environ);
    }
    environ = new_environ;

    return (0);
}
