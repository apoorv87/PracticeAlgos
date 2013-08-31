#include <stdio.h>
#include <stdlib.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(char *s, int i, int n)
{
    int j;
    if (i==n)
    {
        printf("\n%s", s);
    }
    else
    {
        for (j=i; j<=n; j++)
        {
            swap(s+i, s+j);
            permute(s, i+1, n);
            swap(s+i, s+j);
        }
    }
}

int main()
{
    char str[4] = "abcd";
    printf("Hello World!\n");
    permute(str, 0, 3);
    return 0;
}
