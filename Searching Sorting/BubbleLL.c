#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} node;

node* createNode(int value){
    node* newNode = (node *)malloc(sizeof(node));
    if(newNode == NULL){
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

node* createList(int value, node* head){
    node * newNode = createNode(value);
    if(newNode == NULL){
        return NULL ;
    }
    if(head == NULL){
        head = newNode;
    }
    else{
        node * temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    return head;
}

void displayList(node* head){
    if(head == NULL){
        return;
    }
    node * temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

node* bubbleSort(node* head){
    node* temp = head;
    node * ptr = head;
    while(ptr->next->next != NULL ){
        while(temp->next!= NULL && temp->next->next != NULL){
            if(temp->data > temp->next->data){
                int value = temp->data;
                temp->data = temp->next->data;
                temp->next->data = value;

                temp= temp->next;
            }
        }
        ptr = ptr->next;
    }
    return head;
}

int main() {
    node *head = NULL;
    int n;
    while(scanf("%d", &n) == 1){
        head = createList(n, head);
    }
    head = bubbleSort(head);
    displayList(head);
    
    return 0;
}
