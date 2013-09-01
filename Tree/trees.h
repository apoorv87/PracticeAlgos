struct node
{
    int data;
    struct node *left;
    struct node *right;
};

extern struct node* insert(struct node* root, int val);
extern int lookup(struct node *root, int val);
extern struct node* delete_node(struct node *root, int val); 
extern void display(struct node *root);
extern int min(struct node *root);
extern void printpaths(struct node *root, int path[], int pathlen);
