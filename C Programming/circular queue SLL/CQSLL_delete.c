#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void insert();
void delete ();
void display();
void main()
{
    int n, ch, k = 1;
    do
    {
        printf("1-insert\n2-delete\n3-display\n4-exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter a valid number \n");
            break;
        }
    } while (k == 1);
}

void insert()
{
    int i;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter a value :");
    scanf("%d", &i);
    temp->data = i;
    temp->next = NULL;
    if (rear == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = rear->next;
    }
}

void delete ()
{
    if (front == NULL)
    {
        printf("Queue is empty : \n");
    }
    else
    {
        struct node *temp;
        temp = front;
        front = front->next;
        printf("delete %d \n", temp->data);
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp = front;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}