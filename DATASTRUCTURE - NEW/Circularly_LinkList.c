#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *root = NULL;
int len;

void append()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter node data = ");
    scanf("%d", &tmp->data);
    tmp->link = NULL;
    if (root == NULL)
    {
        root = tmp;
        tmp->link = root;
    }
    else
    {
        struct node *p;
        p = root;
        do
        {
            p = p->link;
        } while (p->link != root);
        p->link = tmp;
        tmp->link = root;
    }
    printf("Node had been appended to the list.\n");
}

void addatBegin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data in node : ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (root == NULL)
    {
        root = temp;
        temp->link = root;
    }
    else
    {
        struct node *p;
        p = root;
        do
        {
            p = p->link;
        } while (p->link != root);
        p->link = temp;
        temp->link = root;
        root = temp;
    }
    printf("Node is added at begin");
}

int length()
{
    int c = 0;
    struct node *p = root;
    do
    {
        c++;
        p = p->link;

    } while (p != root);

    return c;
}
void display()
{
    struct node *p;
    p = root;
    printf("Elements are \n");
    do
    {
        printf("%d -> ", p->data);
        p = p->link;
    } while (p != root);
}

void addAtAfter()
{
    int loc, i = 0;

    printf("enter location after which u want to enter : ");
    scanf("%d", &loc);

    if (loc > length())
    {
        printf("Invalid location");
    }
    else
    {
        struct node *p = root;

        while (i < loc)
        {
            p = p->link;
            i++;
        }

        struct node *temp = (struct node *)malloc(sizeof(struct node));
        printf(" enter data for the node \n ");
        scanf("%d", &temp->data);
        temp->link = NULL;

        temp->link = p->link;
        p->link = temp;

        printf("Entered data was added at %d", loc);
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

            temp->link = NULL;
            root = NULL;
            free(temp);
        }
        else
        {
            struct node *p;
            p = root;
            do
            {
                p = p->link;
            } while (p->link != root);
            p->link = temp->link;
            root = temp->link;
            temp->link = NULL;
            free(temp);
        }
    }
    else
    {
        struct node *p;
        int i = 1;
        while (i < loc - 1)
        {
            i++;
            temp = temp->link;
        }
        p = temp->link;
        temp->link = p->link;
        p->link = NULL;
        free(p);
    }
    printf("Node Deleted ");
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
            addatBegin();
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
