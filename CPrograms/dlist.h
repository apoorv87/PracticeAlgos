struct node
{
    int data;
    struct node *nextf;
    struct node *nextb;
};

extern void insertHead(struct node **head, struct node **tail, int val);
extern void insertTail(struct node **head, struct node **tail, int val);
extern void displayHead(struct node *head);
extern void displayTail(struct node *tail);
extern void deleteHead(struct node **head, struct node **tail);
extern void deleteTail(struct node **head, struct node **tail);








