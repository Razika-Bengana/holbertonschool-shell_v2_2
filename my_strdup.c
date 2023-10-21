#include "main.h"

char *my_strdup(const char *str)
{
    size_t length = my_strlen(str) + 1;
    char *new_str = (char *) malloc(length);

    if (new_str == NULL)
    {
        return (NULL);
    }
    my_strcpy(new_str, str);

    return (new_str);
}