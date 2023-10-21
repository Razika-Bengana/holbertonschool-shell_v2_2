#include "main.h"

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    const size_t chunk_size = 128;
    size_t num_read = 0;
    int c;

    if (lineptr == NULL || n == NULL || stream == NULL)
    {
        return -1;
    }

    if (*lineptr == NULL)
    {
        *lineptr = malloc(chunk_size);
        if (*lineptr == NULL)
        {
            return -1;
        }
        *n = chunk_size;
    }

    while (1)
    {
        c = fgetc(stream);

        if (c == EOF)
        {
            if (num_read == 0)
            {
                return -1;
            }
            break;
        }

        if (num_read + 1 >= *n)
        {
            char *new_lineptr = realloc(*lineptr, *n + chunk_size);
            if (new_lineptr == NULL)
            {
                return -1;
            }
            *lineptr = new_lineptr;
            *n += chunk_size;
        }

        (*lineptr)[num_read] = (char) c;
        num_read++;

        if (c == '\n')
        {
            break;
        }
    }

    (*lineptr)[num_read] = '\0';

    return ((ssize_t) num_read);
}
