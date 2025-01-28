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

node* findMiddle(node* head){

    node* slow = head;
    node* fast = head->next;

    while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
node* mergeTwoList(node* left, node* right){
    node* dummyNode = createNode(-1);
    node* t1 = left;
    node* t2 = right;
    node * temp = dummyNode;
    while(t1!= NULL && t2 != NULL){
        if(t1->data < t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1 != NULL){
        temp->next = t1;
    }
    else{
        temp->next = t2;
    }
    return dummyNode->next;
}
node* mergeSort(node* head){
    if(head == NULL || head->next == NULL) return head;
    node* middle = findMiddle(head);
    node* left = head;
    node* right = middle->next;
    middle->next = NULL;
    left = mergeSort(left);
    right = mergeSort(right);
    return mergeTwoList(left, right);
}
int main() {
    node *head = NULL;
    int n;
    while(scanf("%d", &n) == 1){
        head = createList(n, head);
        if(getchar() == '\n') break;
    }
    head = mergeSort(head);
    displayList(head);
    
    return 0;
}
