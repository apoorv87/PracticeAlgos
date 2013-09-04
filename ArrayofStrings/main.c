#include <stdio.h>
#include <stdlib.h>

void countStrings(char *s, int index, int *combs, int len)
{
    if (index < (len - 1))
    {
        printf("\nindex: %d", index);
        countStrings(s, index+1, combs, len);
        if (((s[index] >= '1') && (s[index] <= '2')) && ((s[index+1] >= '1') && (s[index+1] <= '6')))
        {
           countStrings(s, index+2, combs, len);
        }
        return;
    }
    else
    {
        (*combs)++;
        return;
    }
}

int main()
{
    int *combs;
    printf("Hello world!\n");
    char str[10] = "121111";
    countStrings(str, 0, combs, 6);
    printf("Max combs: %d", *combs);
    return 0;
}
