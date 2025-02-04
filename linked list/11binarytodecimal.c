#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

node *createList(node *head, int data)
{
    node *newNode = createNode(data);

    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        return NULL;
    }

    if (head == NULL)
    {
        return newNode;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node *reverse(node *head)
{

    node *prev = NULL;
    node *current = head;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int decimal(node* head){
    node* temp = head;
    int sum = 0;
    int base = 1;
    while(temp != NULL){
        int data = temp->data;
        sum += data*base;
        base = base*2;
        temp = temp->next;
    }

    return sum;
}

int main()
{
    node *head = NULL;
    int data;
    while (scanf("%d", &data) == 1)
    {
        head = createList(head, data);
        if (getchar() == '\n')
        {
            break;
        }
    }

    node *newHead = reverse(head);
    int result = decimal(newHead);
    printf("%d", result);

    return 0;
}