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

node *findMiddle(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

node *merge(node *head1, node *head2)
{
    node *dummy = createNode(-1);
    node *t1 = head1;
    node *t2 = head2;
    node *temp = dummy;
    while (t1 != NULL && t2 != NULL)
    {
        temp->next = t1;
        t1 = t1->next;
        temp = temp->next;

        temp->next = t2;
        t2 = t2->next;
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

    node *newHead = dummy->next;
    free(dummy);
    return newHead;
}
node *reorder(node *head)
{
    if(head == NULL || head->next == NULL) return head;
    node *middle = findMiddle(head);
    node *left = head;
    node *right = middle->next;
    middle->next = NULL;

    // if(right == NULL) return left;

    node *temp = reverse(right);
    node *newHead = merge(left, temp);
    return newHead;
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

    node *newHead = reorder(head);
    display(newHead);

    return 0;
}