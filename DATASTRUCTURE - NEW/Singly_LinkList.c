#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *Link;
};

struct node *root = NULL;

void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data");
    scanf("%d", &temp->data);
    temp->Link = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        while (p->Link != NULL)
        {
            p = p->Link;
        }
        p->Link = temp;
    }
    printf("New node has been Added");
}

void addAtBegin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data");
    scanf("%d", &temp->data);
    temp->Link = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->Link = root;
        root = temp;
    }
    printf("New node has been Added in the begining");
}

int length()
{
    struct node *p = root;
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->Link;
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
        struct node *p = root;

        while (i < loc)
        {
            p = p->Link;
            i++;
        }

        temp = (struct node *)malloc(sizeof(struct node));

        printf("enter data");
        scanf("%d", &temp->data);
        temp->Link = NULL;

        temp->Link = p->Link;
        p->Link = temp;
        printf("Element was added after location : %d", loc);
    }
}

void display()
{
    printf("Elements of Linklist are: \n");
    struct node *p = root;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->Link;
    }
}

void delete ()
{
    int loc;
    struct node *temp;
    printf("Enter Location of the element you want to delete ");
    scanf("%d", &loc);

    if (loc > length())
    {
        printf("Lunth ho kya");
    }
    else if (loc == 1)
    {
        temp = root;
        root = temp->Link;
        temp->Link = NULL;
        free(temp);
        printf("Element at %d location is deleted", loc);
    }
    else
    {
        struct node *p = root;
        struct node *temp;

        int i = 1;

        while (i < loc - 1)
        {
            p = p->Link;
            i++;
        }

        temp = p->Link;
        p->Link = temp->Link;
        temp->Link = NULL;
        free(temp);
        printf("Element at %d location is deleted", loc);
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
            delete ();
            break;
        }
        case 5:
        {

            display();
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
