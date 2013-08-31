#include <stdio.h>

int main()
{
    int a[8] = { 12, 4, 5, 9, 1, 6, 10, 2 } ;
    int key, j, i;
    for (j=1; j < 8; j++)
    {
        i = j - 1;
        key = a[j];
        while ((key < a[i]) && (i>=0))
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
    printf("Sorted Array\n");
    for (j=0; j<8; j++)
    {
        printf("  %d", a[j]);
    }
}



