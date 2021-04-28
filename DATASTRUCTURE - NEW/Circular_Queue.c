#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define size 10

int front = -1, rear = -1;
int ar[size];

void enqueue(int element)

{

    if ((rear + 1) % size == front)
    {
        printf("queue is full");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        ar[rear] = element;
    }
    else
    {
        rear = (rear + 1) % size;
        ar[rear] = element;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        printf("element that is being deleted is %d", ar[front]);
        front = (front + 1) % size;
    }
}

void display()
{
    printf("Circular queue Elements are : ");
    int i = front;
    while (i != rear)
    {
        printf("%d ->", ar[i]);
        i = (i + 1) % size;
    }
    printf(" %d ", ar[i]);
}

int main()
{
    int ch = 0;
    while (ch != 4)
    {
        printf("\n.................Queue Implementation................. \n");
        printf("1 to insert element \n");
        printf("2 to delete element \n");
        printf("3 to display element \n");
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

            enqueue(element);
            break;
        }
        case 2:
        {
            dequeue();
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
