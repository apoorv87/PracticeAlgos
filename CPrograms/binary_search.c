#include <stdio.h>

int search(int *a, int elem, int lindex, int rindex)
{
    int mid = (lindex + rindex)/2;
    if (lindex > rindex)
    {
        return 0;
    }
    if (elem == a[mid])
    {
        return 1;
    }
    else if (elem < a[mid])
    {
        return search(a, elem, lindex, mid-1);
    }
    else if (elem > a[mid])
    {
        return search(a, elem, mid+1, rindex);
    }
}

int main()
{
    int a[6] = {3, 7, 10, 12, 14, 15};
    int val = 25, found = 0, diff, i;
    for (i=0; i<6; i++)
    {
        diff = val - a[i];
        if (search(&a[i+1], diff, 0, (6-(i+2))))
        {   
            found = 1;
            break;
        }        
    }
    if (found)
        printf("Val found in sorted array %d", a[i]);
    else
        printf("val not found in sorted array");
}
