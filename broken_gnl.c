#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

char    *ft_strdup(const char *str)
{
    char    *copy;
    int        i;

    copy = (char *)malloc(sizeof(char) * strlen(str) + 1);
    if (copy == NULL)
        return (NULL);
    i = 0;
    while (str[i] != '\0')
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

char    *get_next_line(int fd)
{
    static char    buffer[BUFFER_SIZE];
    char        line[70000];
    static int    b_read;
    static int    b_pos;
    int            i;

    i = 0;
    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    // printf ("dkhal \n");
    while (1)
    {
        // printf ("loop \n");
        if (b_pos >= b_read)
        {
            // printf ("condition b_pos >= b_read, b_pos = %d, b_pos = %d\n", b_read, b_pos);
            b_read = read(fd, buffer, BUFFER_SIZE);
            b_pos = 0;
            if (b_read <= 0)
            {
                // printf ("condition b_read <= 0\n");
                break ;
            }
        }
        line[i++] = buffer[b_pos++];
        if (buffer[b_pos - 1] == '\n')
        {
            // printf ("condition buffer[b_pos - 1] == nl\n");
            break ;
        }
    }
    line[i] = '\0';
    if (i == 0){
        // printf ("condition i == 0\n");
        return (NULL);
    }
    // printf ("finished\n");
    return (ft_strdup(line));
}

int main ()
{
    char *str = NULL;
    while (1)
    {
        str = get_next_line(0);
        if (!str)
        {
            printf ("return is NULL\n");
            return 1;
        }
        printf ("read : %s\n", str);
    }
}
