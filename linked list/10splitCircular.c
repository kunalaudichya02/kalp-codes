#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} node;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

node* createList(node* head, int data){
    node* newNode = createNode(data);

    if(newNode == NULL){
        printf("Memory allocation failed");
        return NULL;
    }

    if(head == NULL){
        head = newNode;
        head->next = head;
        return head;
    }

    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;

    return head;
}

void display(node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head); 

    printf("\n");
}

node *findMiddle(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
int main(){
    node* head = NULL;
    int data;
    while (scanf("%d", &data) == 1)
    {
        head = createList(head, data);
        if (getchar() == '\n')
        {
            break;
        }
    }
    node* middle = findMiddle(head);
    node* right = middle->next;
    middle->next = head;

    node* temp = right;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = right;

    display(head);
    display(right);

return 0;
}