#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *root = NULL;

void append()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter data for the node :");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (root == NULL)
    {
        root = temp;
        root->prev = temp;
        temp->next = root;
    }
    else
    {
        struct node *p = root;

        do
        {

            p = p->next;

        } while (p->next != root);

        p->next = temp;
        temp->prev = p;
        temp->next = root;
        root->prev = temp;
    }

    printf("Element was added in the end");
}

void display()
{

    struct node *p = root;
    printf("elements of linkedlist are \n");
    do
    {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != root);
}

void addAtBegin()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter data for the node :");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    if (root == NULL)
    {
        root = temp;
        root->prev = temp;
        temp->next = root;
    }

    else
    {
        struct node *p = root;

        do
        {
            p = p->next;
        } while (p->next != root);

        p->next = temp;
        temp->prev = p;
        temp->next = root;
        root->prev = temp;
        root = temp;
    }
    printf("element was added at the beginning");
}

int length()
{
    int c = 0;
    struct node *p = root;
    do
    {
        c++;
        p = p->next;

    } while (p != root);

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

int delete ()
{
    int len = length();
    struct node *temp;
    temp = root;
    int loc;
    printf("Enter location");
    scanf("%d", &loc);
    if (loc > len)
    {
        printf("Invalid Location ");
        return 0;
    }
    if (loc == 1)
    {
        if (len == 1)
        {

            temp->next = NULL;
            temp->prev = NULL;
            root = NULL;
            free(temp);
        }
        else
        {

            struct node *p = root;
            do
            {
                p = p->next;

            } while (p->next != root);
            struct node *temp = root;

            p->next = temp->next;

            temp->next->prev = p;

            root = temp->next;
            temp->prev = NULL;
            temp->next = NULL;
            free(temp);
        }
    }
    else
    {
        struct node *p = root;
        int i = 1;
        while (i < loc - 1)
        {
            i++;
            p = p->next;
        }
        struct node *temp;
        temp = p->next;
        temp->next->prev = p;
        p->next = temp->next;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
}

int main()
{
    int ch = 0;
    while (ch != 6)
    {
        printf("\n.................Circular Doubly Implementation................. \n");
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
        getch();
        system("cls");
    }
}
