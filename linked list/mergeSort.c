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
        return NULL;

    if (head == NULL)
        return newNode;

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
    node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

node *findMiddle(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node *merge(node *left, node *right)
{
    node *dummy = createNode(-1);
    node *temp = dummy;

    node *t1 = left;
    node *t2 = right;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data <= t2->data)
        {
            temp->next = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            t2 = t2->next;
        }
        temp = temp->next;
    }

    while (t1 != NULL)
    {
        temp->next = t1;
        t1 = t1->next;
        temp = temp->next;
    }
    while (t2 != NULL)
    {
        temp->next = t2;
        t2 = t2->next;
        temp = temp->next;
    }

    node *head = dummy->next;
    free(dummy);
    return head;
}
node *sort(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *middle = findMiddle(head);
    node *left = head;
    node *right = middle->next;
    middle->next = NULL;
    node *leftt = sort(left);
    node *rightt = sort(right);

    return merge(leftt, rightt);
}


node* reverse(node* head){
    node* prev = NULL;
    node* next = NULL;
    node* current = head;

    while(current!= NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}
int main()
{
    node *head = NULL;
    int data;
    while (scanf("%d", &data) == 1)
    {
        head = createList(head, data);
        char c = getchar();
        if (c == '\n')
            break;
    }
    head = sort(head);
    // head = reverse(head);
    display(head);
}