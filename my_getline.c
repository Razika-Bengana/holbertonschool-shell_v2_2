#include "main.h"

ssize_t my_getline(char **lineptr, size_t *n)
{
    size_t pos = 0;
    char ch;
    if (!lineptr || !n)
    {
        errno = EINVAL;
        return (-1);
    }

    if (*lineptr == NULL)
    {
        *n = 128;
        *lineptr = malloc(*n);
        if (*lineptr == NULL)
            return (-1);
    }

    while (read(STDIN_FILENO, &ch, 1) > 0)
    {
        if (pos >= *n)
        {
            *n *= 2;
            char *new_ptr = realloc(*lineptr, *n);
            if (!new_ptr)
            {
                return (-1);
            }
            *lineptr = new_ptr;
        }

        (*lineptr)[pos++] = ch;

        if (ch == '\n')
            break;
    }

    (*lineptr)[pos] = '\0';

    return (pos);
}
