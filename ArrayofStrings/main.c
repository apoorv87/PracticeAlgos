#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int *combs, i;
    printf("Hello world!\n");
    char str[10] = "12111";
    char word[10] = "hello";
    char *dict[10];
    countStrings(str, 0, combs, 5);
    printf("Max combs: %d", *combs);
    //dict[0] = (char *)malloc(sizeof(char)*10);
    //dict[1] = (char *)malloc(sizeof(char)*10);
    //strcpy(dict[0], word);
    //printf("string: %s", dict[0]);
    //Array of Strings

    for (i=0; i<10; i++)
    {
        //strcat(word, itoa(i, buff, 10));
        //printf("\nWord: %s", word);
        dict[i] = (char *)malloc(sizeof(char)*10);
        strcpy(dict[i], word);
        printf("\nString: %s", dict[i]);
    }
    return 0;
}
