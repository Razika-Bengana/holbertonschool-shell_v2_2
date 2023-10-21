#include "main.h"


char *my_strchr(const char *s, int c)
{
    if (s == NULL)
    {
        return NULL;
    }
    while (*s != '\0')
    {
        if (*s == (char)c)
        {
            return (char *)s;
        }
        s++;
    }

    if (*s == (char)c)
    {
        return (char *)s;
    }
    return (NULL);
}
