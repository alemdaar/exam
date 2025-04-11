#include <stdio.h>
#include <string.h>

// this not my code, this is an ai code, still trying to figure out an algo for this problem )
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int start, int end) {
    if (start == end) {
        printf("%s\n", str); // Print the permutation
    } else {
		int i = start;
		while (i <= end)
		{
            swap(&str[start], &str[i]);
            permute(str, start + 1, end);
            swap(&str[start], &str[i]);
			i++;
        }
    }
}

int main() {
    char str[100];
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 0;
    int n = strlen(str);
    printf("All permutations of %s are:\n", str);
    permute(str, 0, n - 1);
    return 0;
}