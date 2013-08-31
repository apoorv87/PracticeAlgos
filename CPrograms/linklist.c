#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void sortedInsert(struct node **head, int val)
{
    struct node *temp, *curr, *temp1;
    if (*head == NULL)
    {
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->data = val;
        (*head)->next = NULL;
    }
    else
    {
        if (val < (*head)->data)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = val;
            temp->next = *head;
            *head = temp;
        }
        else
        {
            curr = *head;
            //printf("\n\tPrinting %d", curr->data);
            while(curr != NULL)
            {
                //printf("\nPrinting %d", (*head)->data);
                if (curr->next != NULL)
                {
                if (val < ((curr->next)->data))
                {
                    temp1 = curr->next;
                    temp = (struct node *)malloc(sizeof(struct node));
                    temp->data = val;
                    temp->next = temp1;
                    curr->next = temp;
                    break;
                }
                else
                {
                    curr = curr->next;
                }
                }
                else
                {
                    temp = (struct node *)malloc(sizeof(struct node));
                    temp->data = val;
                    temp->next = NULL;
                    curr->next = temp;
                    break;
                }
            } 
        }
    }
}

void sort(struct node **head)
{
    struct node *tempHead = NULL;
    struct node *curr = *head;
    struct node *prev;

    while(curr != NULL)
    {
        sortedInsert(&tempHead, curr->data);
 //       printf("\n\t%d", tempHead->data);
        prev = curr;
        curr = curr->next;
        free(prev);
//        printf("\n%d Printing", curr->data);
    }
    *head = tempHead;
}

void display(struct node *head)
{
    printf("\n\tDisplay: ");
    while (head != NULL)
    {
        printf("\n\t%d", head->data);
        head = head->next;
    }    
}

void reverse_display(struct node *head)
{
    struct node *temp = head;
    if (temp->next != NULL)
    {
        reverse_display(temp->next);
    }
    printf("\n\t%d\n", temp->data);
}

void reverse_list(struct node **head)
{
    struct node *temp = *head;
    struct node *temp1, *prev;
    while (temp != NULL)
    {
        temp1 = temp->next;
        if (temp == *head)
        {
            temp->next = NULL;
        }
        else
        {
            temp->next = prev;
        }
        prev = temp;
        temp = temp1;
    }
    *head = prev;
}

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 3;
    head->next = (struct node *)malloc(sizeof(struct node));
    (head->next)->data = 1;
    (head->next)->next = (struct node *)malloc(sizeof(struct node));
    ((head->next)->next)->data = 2;
    ((head->next)->next)->next = NULL;  
    display(head);
    sort(&head);
    display(head);
    printf("\nReverse List:");
    reverse_display(head);
    reverse_list(&head); 
    display(head);
}








































