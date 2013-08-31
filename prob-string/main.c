#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Hello world!\n");
    char str[80] = "1";
    char buf[80];
    printf("Char: %c", str[1]);
    int i,j,k,len = 1, count;
    for (k=1; k<=5; k++)
    {
        i=0;
        j=0;
        printf("\nLength is %d", len);
        strcpy(buf, str);
        while(i<len)
        {
            count = 1;
            while (buf[i+1] == buf[i])
            {
                count++;
                i++;
            }
            str[j++] = (char)(count + 48);
            str[j++] = buf[i];
            i++;
        }
        str[j] = '\0';
        len = j;
        printf("\n The string is : %s", str);
    }
    return 0;
}
