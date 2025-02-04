#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
} node;

node* createNode(node* head, int value){
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL){
        printf("Memory failed");
        return NULL;
    }
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

node* insertAtEnd(node* head, int value){
    node* newNode = createNode(head, value);
    if(newNode == NULL){
        printf("Memory failed");
        return head;
    }

    if(head ==NULL){
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
        printf("List is empty");
        return ;
    }
    node* temp = head;
    do{
        printf("%d ", temp->value);
        temp = temp->next;
    }while(temp != head);
}
int main(){
    node* head = NULL;

   head = insertAtEnd(head, 1);
   head = insertAtEnd(head, 2);
   head = insertAtEnd(head, 3);
   head = insertAtEnd(head, 3);
   head = insertAtEnd(head, 3);
    
    display(head);
    return 0;
}