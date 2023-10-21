#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void exec_cmd(char **argv);
void exec_cd(char **argv);
char *get_location(char *command);

char *my_strcpy(char *dest, const char *src);
char *my_strcat(char *dest, const char *src);
size_t my_strlen(const char *str);
char *my_strdup(const char *str);
int my_strncmp(const char *s1, const char *s2, size_t n);
int my_strcmp(const char *s1, const char *s2);
char *my_strchr(const char *s, int c);

char *my_getenv(const char *name);
int my_setenv(const char *name, const char *value, int overwrite);


#endif /* MAIN_H */
