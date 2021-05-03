#include <stdio.h>
#include <conio.h>

#define size 5

int stack[size];
int top = -1;

void push(int element)
{
    if (top == size - 1)
    {
        printf("stack is full");
    }
    else
    {
        top = top + 1;
        stack[top] = element;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("underflow");
    }
    else
    {
        printf("element to be deleted %d", stack[top]);
        top = top - 1;
    }
}

void display()
{

    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Stack elements are \n");
        for (int x = top; x >= 0; x--)
        {
            printf(" %d <- ", stack[x]);
        }
    }
}

int main()
{
    int ch = 0;
    while (ch != 4)
    {
        printf("\n.................Queue Implementation................. \n");
        printf("1 to push \n");
        printf("2 to pop \n");
        printf("3 to display  \n");
        printf("4 to exit\n");
        printf("Enter your choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            int element;
            printf("enter element to insert");
            scanf(" %d", &element);

            push(element);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {

            printf("program has ended");
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
