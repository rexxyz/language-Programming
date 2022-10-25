#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;
void createList(int n);
void insertinorder(int data);
void displayList();
int main()
{
    int n, data;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("\nData in the list \n");
    displayList();
    printf("\nEnter data to insert in order of the list: ");
    scanf("%d", &data);
    insertinorder(data);
    printf("\nData in the list \n");
    displayList();
    return 0;
}
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = head;
        temp = head;
        for (i = 2; i <= n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if (newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newNode->data = data;
                newNode->next = head;
                temp->next = newNode;
                temp = temp->next;
            }
        }
        printf("Circular LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
void insertinorder(int data)
{
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        if (head == NULL || head->data >= newNode->data)
        {
            newNode->next = head;
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            head = newNode;
        }
        else
        {
            temp = head;
            while (temp->next != head && temp->next->data < newNode->data)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
void displayList()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        do
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}
