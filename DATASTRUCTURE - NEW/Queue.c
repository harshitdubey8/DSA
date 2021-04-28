/* enque dequeue display main() **/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define size 10

int ar[size];

void insert();
void delete ();
void display();

int rear = -1;
int front = -1;

void insert()
{
    int add;

    if (rear == size - 1)
    {
        printf("overflow  queue");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        printf("enter the element : ");
        scanf("%d", &add);
        rear = rear + 1;
        ar[rear] = add;
    }
}

void delete ()
{
    if (front == -1 && rear == -1 || front > rear)
    {
        printf("array is empty");
    }
    else
    {
        printf("Deleted item %d", ar[front]);
        front = front + 1;
    }
}

void display()
{
    if (rear == -1 || front > rear)
    {
        printf("array is empty \n");
    }
    else
    {

        printf("queue elements are");
        for (int x = front; x <= rear; x++)
        {
            printf("%d \n", ar[x]);
        }
        printf("/n");
    }
}

int main()
{
    int ch = 0;
    while (ch != 4)
    {
        printf(".................Queue Implementation................. \n");
        printf("1 to insert element \n");
        printf("2 to delete element \n");
        printf("3 to display element \n");
        printf("4 to exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {

            insert();
            break;
        }
        case 2:
        {
            delete ();
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
