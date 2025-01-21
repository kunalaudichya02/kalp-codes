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

node* removeElement(node* head, int k, int count){
    node* temp = head;
    node* prev = NULL;
    int index =1;
    
    while(temp != NULL){
        if(index % k == 0){
            node* remove = temp;
            prev->next = temp->next;
            free(remove);
            temp = prev->next;
            index++;
        }
        else{
            prev= temp;
            temp= temp->next;
            index++;
        }
       }
    return head;
}
int main() {
    node *head = NULL;
    int n;
    int count=0;
    while(scanf("%d", &n) == 1){
        head = createList(n, head);
        count++;
        char c = getchar();
        if(c == '\n'){
            break;
        }
    }
    int k;
    scanf("%d", &k);
    head = removeElement(head, k, count);
    displayList(head);
    
    return 0;
}
