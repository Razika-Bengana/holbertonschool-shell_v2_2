#include "main.h"

char *get_location(char *command)
{
    char *path, *path_copy, *path_token, *file_path;
    size_t command_length, directory_length;
    struct stat buffer;

    path = my_getenv("PATH");

    if (path)
    {
        path_copy = my_strdup(path);
        command_length = my_strlen(command);

        path_token = strtok(path_copy, ":");

        while(path_token != NULL)
        {
            directory_length = my_strlen(path_token);
            file_path = malloc(command_length + directory_length + 2);

            if (file_path == NULL)
            {
                perror("Allocation error");
                exit(EXIT_FAILURE);
            }

            my_strcpy(file_path, path_token);
            my_strcat(file_path, "/");
            my_strcat(file_path, command);
            my_strcat(file_path, "\0");

            if (stat(file_path, &buffer) == 0)
            {
                free(path_copy);

                return (file_path);
            }
            else
            {
                free(file_path);
                path_token = strtok(NULL, ":");

            }
        }
        free(path_copy);

        if (stat(command, &buffer) == 0)
        {
            return (command);
        }
    }
    return (NULL);
}
