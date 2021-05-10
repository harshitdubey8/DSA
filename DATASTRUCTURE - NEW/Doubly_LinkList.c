#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *root = NULL;

void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for the node");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p = root;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
    printf("Element was added in the end");
}

void addAtBegin()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for the node");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->next = root;
        root->prev = temp;
        root = temp;
    }
    printf("new node was added at the begining ");
}

int length()
{
    int c = 0;

    struct node *p = root;
    while (p->next != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

void addAtAfter()
{
    int loc;
    struct node *temp;
    int i = 1;
    printf("Enter Location after which you are willing to add ");
    scanf("%d", &loc);

    if (loc > length())
    {
        printf("Invalid Location");
    }
    else
    {

        temp = (struct node *)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d", &temp->data);
        temp->next = NULL;
        temp->prev = NULL;
        struct node *p = root;
        int i = 1;
        while (i < loc)
        {
            p = p->next;
            i++;
        }
        temp->next = p->next;
        p->next->prev = temp;
        temp->prev = p;
        p->next = temp;

        printf("Element was added somewhere in the between");
    }
}

void traverse()
{
    printf("Elements of Linklist are: \n");
    struct node *p = root;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
}

void delete ()
{
    int loc, l, i = 0;
    struct node *temp;
    printf("Enter location to be deleted");
    scanf("%d", &loc);
    l = length();
    if (loc > l)
    {
        printf("Invalid Location");
    }
    else if (loc == 1)
    {
        temp = root;
        root = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        free(temp);
        printf("Node was deleted");
    }
}

int main()
{
    int ch = 0;
    while (ch != 6)
    {
        printf("\n.................Singly LinkList Implementation................. \n");
        printf("1 to append \n");
        printf("2 to AddAtBegin element \n");
        printf("3 to AddAtAfter element \n");
        printf("4 to Delete element \n");
        printf("5 to display\n");
        printf("6 to exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            append();
            break;
        }
        case 2:
        {
            addAtBegin();
            break;
        }
        case 3:
        {
            addAtAfter();
            break;
        }
        case 4:
        {
            // delete ();
            break;
        }
        case 5:
        {

            traverse();
            break;
        }

        case 6:
        {

            printf("the program has ended");
            break;
        }
        default:
        {
            printf("Wrong choice MF");
            break;
        }
        }
    }
}
