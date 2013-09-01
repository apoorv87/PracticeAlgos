#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    char temp;
    temp =*a;
    *a = *b;
    *b = temp;
}

void printPerm(char *str, int len, int index)
{
    int i;
    if (index < (len -1))
    {
        for (i=index; i<len; i++)
        {
            swap(&str[index], &str[i]);
            printPerm(str, len, index+1);
            swap(&str[index], &str[i]);
        }
    }
    else
    {
        printf("\nPermutation: %s", str);
    }
}

int main()
{
    printf("Hello world!\n");
    char str[40] = "ABCD";
    printPerm(str, 4, 0);
    return 0;
}
