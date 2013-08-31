#include <stdio.h>
#include <stdlib.h>
int enq_index = -1, deq_index = -1;

void insert(int a[], int val)
{
    if (!((enq_index - deq_index) == 10))
    {
        enq_index++;
        printf("\nInserted");
        a[enq_index % 10] = val;
    }
    else
    {
        printf("Queue is full");
    }
}

int delete_queue(int a[])
{
    int val;
    if (deq_index == enq_index)
    {
        printf("Queue is empty");
    }
    else
    {
        deq_index++;
        printf("\ndeleted");
        val = a[deq_index % 10];
    }
}


int main()
{
    printf("Hello world!\n");
    int a[10], i;
    for (i=0; i<11; i++)
    {
        insert(a, i);
    }
    for (i=0; i<11; i++)
    {
        delete_queue(a);
    }
    return 0;
}
