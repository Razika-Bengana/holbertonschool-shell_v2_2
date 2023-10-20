#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void exec_cmd(char **argv);
char *get_location(char *command);
char *my_strcpy(char *dest, const char *src);
char *my_strcat(char *dest, const char *src);
size_t my_strlen(const char *str);
char *my_strdup(const char *str);



#endif /* MAIN_H */
