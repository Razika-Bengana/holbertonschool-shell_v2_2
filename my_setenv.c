#include "main.h"

extern char **environ;

int my_setenv(const char *name, const char *value, int overwrite)
{
    char *new_entry;
    size_t name_len, value_len;
    int i;
    int env_len = 0;

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
                if (environ[i] == NULL)
                {
                    fprintf(stderr, "environ[%d] is NULL\n", i);
                    return (-1);
                }
                char *new_value = malloc(name_len + value_len + 2);

                if (new_value == NULL)
                {
                    return -1;
                }
                my_strcat(my_strcat(my_strcat(new_value, name), "="), value);
                environ[i] = new_value;
            }
            return 0;
        }
    }

    char **new_environ = malloc(sizeof(char *) * (env_len + 2));
    if (new_environ == NULL)
    {
        return (-1);
    }

    for (i = 0; i < env_len; i++)
    {
        new_environ[i] = environ[i];
    }

    new_entry = malloc(name_len + value_len + 2);
    if (new_entry == NULL)
    {
        free(new_environ);
        return (-1);
    }
    my_strcat(my_strcat(my_strcat(new_entry, name), "="), value);
    new_environ[env_len] = new_entry;
    new_environ[env_len + 1] = NULL;

    environ = new_environ;

    return (0);
}
