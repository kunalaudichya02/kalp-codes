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
        return NULL;
    }
    if(head == NULL){
        return newNode;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

void display(node* head){
    if(head == NULL){
        return ;
    }
    node * temp = head;
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node* findMiddle(node* head){
    node* slow =head;
    node* fast = head;

    while(fast != NULL && fast->next!= NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main(){
    node* head = NULL;
    int data;
    while(scanf("%d", &data)==1){
        head = createList(head, data);
        if(getchar()=='\n') break;
    }

    node* mid = findMiddle(head);
    printf("%d", mid->data);
    return 0;
}