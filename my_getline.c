#include "main.h"

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    char *buffer;
    size_t bufsize;
    size_t position = 0;
    int ch;

    if (lineptr == NULL || n == NULL || stream == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    if (*lineptr == NULL)
    {
        bufsize = 128;
        buffer = malloc(bufsize * sizeof(char));
        if (buffer == NULL)
        {
            return -1;
        }
    }
    else
    {
        buffer = *lineptr;
        bufsize = *n;
    }

    while (1)
    {
        ch = fgetc(stream);

        if (ch == EOF)
        {
            if (position == 0)
            {
                return -1;
            }
            buffer[position] = '\0';
            *lineptr = buffer;
            *n = bufsize;
            return position;
        }

        if (position >= bufsize - 1)
        {
            bufsize *= 2;
            char *new_buffer = realloc(buffer, bufsize * sizeof(char));
            if (new_buffer == NULL)
            {
                free(buffer);
                return -1;
            }
            buffer = new_buffer;
        }

        buffer[position++] = (char) ch;

        if (ch == '\n')
        {
            buffer[position] = '\0';
            *lineptr = buffer;
            *n = bufsize;
            return position;
        }
    }
}
