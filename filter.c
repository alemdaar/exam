#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int mystrlen(char *str)
{
    int i = 0;
    if (!str)
        return i;
    while (str[i])
        i++;
    return i;
}

int equal(char *input, char *str, int position)
{
    int i = 0;
    while (input[i] && input[i] == str[position])
    {
        i++;
        position ++;
    }
    if (!input[i])
        return 1;
    return 0;
}

char *checkit(char *input, char *str)
{
    char *out;
    int i = 0;
    int j = 0;
    while (str[i])
    {
        if (equal(input, str, i) == 1)
        {
            j = 0;
            while (input[j])
            {
                str[i++] = '*';
                j++;
            }
        }
        else
            i++;
    }
    return str;
}


char    *gnl(int fd)
{
    int buffer_size;
    ssize_t r;
    int i;
    int j;
    char *buffer = NULL;
    char *readd = NULL;
    char *str = NULL;
    char *tmp = NULL;
    buffer_size = 1;
    
    // malloc
    while (1)
    {
        readd = malloc (buffer_size + 1);
        if (!readd)
        {
            perror("readd: ");
            return NULL;
        }
        r = read(0, readd, buffer_size);
        if (r == -1)
        {
            free(readd);
            if (buffer)
                free(buffer);
            perror("read: ");
            return NULL;
        }
        else if (r == 0)
        {
            break;
        }
        readd[r] = 0;
        if (buffer)
            tmp = buffer;
        buffer = malloc (mystrlen(tmp) + mystrlen(readd) + 1);
        if (!buffer)
        {
            if (tmp)
                free(tmp);
            free(readd);
            perror("buffer: ");
            return  NULL;
        }
        i = 0;
        if (tmp)
        {
            j = 0;
            while (tmp[j])
                buffer[i++] = tmp[j++];
            free(tmp);
        }
        j = 0;
        while (readd[j])
            buffer[i++] = readd[j++];
        buffer[i] = 0;
        free(readd);
        i = 0;
        while (buffer[i])
        {
            if (buffer[i] == '\n')
                return buffer;
            i++;
        }
    }
    if (r == 0 && buffer == NULL)
    {
        free(readd);
        perror("empty: ");
        return (NULL);
    }
    str = malloc (mystrlen(buffer) + 1);
    if (!str)
    {
        perror("str: ");
        return NULL;
    }
    i = 0;
    while (buffer[i])
    {
        str[i] = buffer[i];
        i++;
    }
    str[i] = 0;
    free(buffer);
    return (str);
}

int main (int ac, char **av)
{
    int i;
    if (ac != 2)
    {
        printf ("argument doesnt equal 2\n");
        return 0;
    }
    char *str = NULL;
    while (1)
    {
        str = gnl(0);
        if (!str)
            return 1;
        str = checkit(av[1], str);
        printf ("%s", str);
    }
}
