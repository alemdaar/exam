#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char    *ft_strdup(const char *str)
{
    char *copy = NULL;
    copy = malloc (sizeof(char) * strlen(str) + 1);
    if (!copy)
        return NULL;
    int i = 0;
    while (str[i] != '\0')
    {
        copy[i] = str[i];
        i++;
    }
    copy = '\0';
    return copy;
}

char *get_next_line(int fd)
{
     
}
