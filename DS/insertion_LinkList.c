#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *root = NULL;

void addatbegin()
{
    struct Node *tmp;
    tmp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter node data = ");
    scanf("%d", &tmp->data);
    tmp->next = NULL;
    if (root == NULL)
    {
        root = tmp;
    }
    else
    {
        tmp->next = root;
        root = tmp;
    }
    printf("Node had been added to the beginning.\n");
}

void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf("%d", n->data);
        n = n->next;
    }
}

int main()
{
    // int test_integer;
    // struct Node *head = NULL;
    // struct Node *second = NULL;
    // struct Node *third = NULL;
    // // memory allocation
    // head = (struct Node *)malloc(sizeof(struct Node));
    // second = (struct Node *)malloc(sizeof(struct Node));
    // third = (struct Node *)malloc(sizeof(struct Node));

    // head->data = 1;
    // head->next = second;
    // second->data = 2;
    // second->next = third;
    // third->data = 3;
    // third->next = NULL;

    int choice;
    printf("enter choice");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:

        addatbegin();

        break;
    case 2:

        printList(head);

    default:
        exit(0);

        break;
    }

    return 0;
}
