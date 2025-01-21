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

node* removeElement(node* head, int key){
    node* temp = head;
    if(temp->data == key && temp->next ==NULL){
        return 0;
    }
    while(temp->next != NULL){
        if(temp->next->data == key){
            node* remove = temp->next;
            temp->next = remove->next;
            free(remove);
        }
        else{
            temp = temp->next;   
        }
    }
    return head;
    // node* temp = head;
    // node* prev = NULL;
    // while(temp != NULL){
    //     if(temp->data == key){
    //         if(temp == head){
    //             node* remove = temp;
    //             head = temp->next;
    //             free(remove);
    //             temp = head;
    //         }
    //         else{
    //             prev->next = temp->next;
    //             free(temp);
    //             temp = prev->next;
    //         }
    //     }
    //     prev = temp;
    //     temp = temp->next;
    // }
    // return head;
}

int main() {
    node *head = NULL;
    int n;
     while (scanf("%d", &n) == 1) {
        head = createList(n, head); 
        char c = getchar();
        if (c == '\n') {
            break;
        }
    }
    int key;
    scanf("%d", &key);
    head = removeElement(head, key);
    displayList(head);
    
    return 0;
}
