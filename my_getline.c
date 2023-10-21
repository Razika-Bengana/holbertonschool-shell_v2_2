#include "main.h"

ssize_t my_getline(char **lineptr, size_t *n)
{
    size_t pos = 0;
    size_t bufsize = 128;
    char ch;

    if (lineptr == NULL || n == NULL)
    {
        errno = EINVAL;
        return (-1);
    }

    if (*lineptr == NULL)
    {
        *lineptr = malloc(bufsize);
        if (*lineptr == NULL)
        {
            return (-1);
        }
        *n = bufsize;
    }

    while (1)
    {
        if (read(STDIN_FILENO, &ch, 1) <= 0) // Ligne modifiée
        {
            if (pos == 0)
            {
                return -1;
            }
            (*lineptr)[pos] = '\0';
            return pos;
        }

        if (pos + 1 >= *n)
        {
            bufsize *= 2;
            char *new_buf = malloc(bufsize);
            if (new_buf == NULL)
            {
                return -1;
            }

            for (size_t i = 0; i < pos; ++i)
            {
                new_buf[i] = (*lineptr)[i];
            }
            free(*lineptr);
            *lineptr = new_buf;
            *n = bufsize;
        }

        (*lineptr)[pos++] = ch;

        if (ch == '\n')
        {
            (*lineptr)[pos] = '\0';
            return pos;
        }
    }
}
