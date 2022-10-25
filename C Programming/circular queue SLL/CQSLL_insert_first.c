#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * head;

void createlist(int n);
void insertfirst(int data);
void display();
void main()
{
    int n, i;
    printf("Enter total no. of node : ");
    scanf("%d", &n);
    createlist(n);
    printf("data in list \n");
    display();
    printf("Enter data to insert at first : ");
    scanf("%d", &i);
    insertfirst(i);
    printf("Data in list \n");
    display();
}

void createlist(int n)
{
    struct node *newnode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter data of node 1 : ");
    scanf("%d", &data);
    head->data = data;
    head->next = head;
    temp = head;
    for (i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of node %d : ", i);
        scanf("%d", &data);
        temp->next = newnode;
        newnode->data = data;
        newnode->next = head;
        temp = temp->next;
    }
    // temp->next=head;
    printf("list created \n");
}

void insertfirst(int data)
{
    struct node *temp, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    head = newnode;
    printf("data inserted\n");
}

void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp = head;
        do
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}
