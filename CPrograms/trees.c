#include <stdio.h>
#include "trees.h"
#include <stdlib.h>
#include <assert.h>

struct node* insert(struct node* root, int val)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        (root)->data = val;
        (root)->left = NULL;
        (root)->right = NULL;
        return root;
    }
    else
    {
        if (val <= root->data)
        {
            root->left = insert(root->left, val);
        }
        else
        {
            root->right = insert((root)->right, val);
        }
        return root;   
    }
}

void display(struct node *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("\n\t%d",root->data);
        display(root->right);
    } 
}

int lookup(struct node *root, int val)
{
    int found;
    if (root == NULL)
    {
        return 0;
    }
    else if (root->data == val)
    {
        return 1;
    }
    else
    {
        if (val < root->data)
        {
            found = lookup(root->left, val);
        }
        else
        {
            found = lookup(root->right,val);
        }
        return found;
    }
}

int min(struct node *root)
{
    int min;
    assert(root != NULL);
    while(root != NULL)
    {
        min = root->data;
        root = root->left;
    }
    return min;
}

struct node* delete_node(struct node *root, int val)
{
    struct node *temp, *temp1, *parent;
    int right, left, rsucc, lsucc;

    if ((root->left == NULL) && (root->right == NULL))
    {
        free(root);
        return NULL;
    }
    else
    {
        temp = root;

        while ((temp != NULL) || (temp->data != val))
        {
            if (val < temp->data)
            {
                parent = temp;
                temp = temp->left;
                left = 1;
                right = 0;
            }
            else if (val > temp->data)
            {
                parent = temp;
                temp = temp->right;
                right = 1;
                left = 0;
            }
            else
                break;
        }

        if (temp != NULL)
        {
            if ((temp->left == NULL) && (temp->right == NULL))
            {
                free(temp);
                if (left)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            else if (temp->left == NULL)
            {
                temp1 = temp->right;
                while (temp1->left != NULL)
                {
                    parent = temp1;
                    temp1 = temp1->left;
                }
                rsucc = temp1->data;
                temp->data = rsucc;
                free(temp1);       
                parent->left = temp;
                temp->right = NULL;         
            }
            else if (temp->right == NULL)
            {
                temp1 = temp->left;
                while (temp1->right != NULL)
                {
                    parent = temp1;
                    temp1 = temp1->right;
                }
                lsucc = temp1->data;
                temp->data = lsucc;
                free(temp1);       
                parent->right = temp;
                temp->left = NULL;                
            }
            else
            {
                temp1 = temp->left;
                while (temp1->right != NULL)
                {
                    parent = temp1;
                    temp1 = temp1->right;
                }
                lsucc = temp1->data;
                temp->data = lsucc;
                if (temp1->left != NULL)
                    parent->right = temp1->left;
                else
                    parent->right = NULL;
                free(temp1);       
            }
        }
        return root;
    } 
}

void printpaths(struct node *root, int path[], int pathlen)
{
    int i;
    if (root != NULL)
    {
        path[pathlen++] = root->data;
        if ((root->left == NULL) && (root->right == NULL))
        {
            printf("\nPath: ");
            for (i=0; i<pathlen; i++)
            {
                printf("%d", path[i]);
            }
        }
        else
        {
            printpaths(root->left, path, pathlen);
            printpaths(root->right, path, pathlen);
        }
    }
}






