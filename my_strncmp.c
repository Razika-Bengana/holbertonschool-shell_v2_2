#include "main.h"

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
    {
        if (s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
    }

    if (i < n)
    {
        if (s1[i] != '\0')
        {
            return (1);
        }
        if (s2[i] != '\0')
        {
            return (-1);
        }
    }

    return (0);
}
