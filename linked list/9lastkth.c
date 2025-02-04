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

// node *reverse(node *head)
// {

//     node *prev = NULL;
//     node *current = head;
//     node *next = NULL;

//     while (current != NULL)
//     {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }

//     return prev;
// }

// node* findKth(node* head, int k){
//     if(head == NULL || head->next == NULL){
//         return head;
//     }
//     node* newHead = reverse(head);
//     node* temp = newHead;
//     while(k>1){
//         temp = temp->next;
//         k--;
//     }

//     return temp;
// }

node* findKth(node* head, int k){
     if(head == NULL || head->next == NULL){
        return head;
    }

    node* t1 = head;
    node* t2 = head;

    for(int i=0; i<k; i++){
        t2 = t2->next;
    }

    while(t2!= NULL){
        t1= t1->next;
        t2 = t2->next;
    }

    return t1;
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
    int k;
    scanf("%d", &k);
    node *n = findKth(head, k);
    printf("%d", n->data);

    return 0;
}