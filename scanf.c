#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int main ()
{
    int num;
    while (1)
    {
        printf("Enter an integer: ");
        scanf("%d", &num);  // Reads an integer
        printf("You entered: %d\n", num);
    }
    
}
