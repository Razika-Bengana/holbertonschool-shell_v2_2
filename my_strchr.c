#include "main.h"


char *my_strchr(const char *s, int c)
{
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
