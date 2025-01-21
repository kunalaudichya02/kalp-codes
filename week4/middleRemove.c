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

node* removeMiddle(node* head, int count){
    node* slow = head;
    node* fast = head;
    node* prev = NULL;
    
    while(fast!= NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    //the temp pointer will now point on the middle element
    prev->next = slow->next;
    free(slow);
    
    return head;
    // node* temp = head;
    // if(count%2 == 1){
    //     //odd
    //     int n= count/2;
    //     node* remove = temp->next;
    //     for(int i=1; i< n; i++){
    //         temp = temp->next;
    //         remove = remove->next;
    //     }
    //     temp->next = remove->next;
    //     free(remove);
    // }
    // else{
    //     //even
    //     int n= count/2;
    //     node* remove = NULL;
    //     for(int i=1; i<= n; i++){
    //         //if(temp->next != NULL && remove->next!=NULL){
    //         remove = temp;
    //         temp = temp->next;

    //         //}
            
    //     }
    //     remove->next = temp->next;
    //     free(temp);
    // }
    // return head;
}

int main() {
    node *head = NULL;
    int n;
    int count =0;
    
    while(scanf("%d", &n) == 1){
        head = createList(n, head);
        count++;
    }
    if(head == NULL || head->next == NULL){
        
        return 0;
    }
    head = removeMiddle(head, count);
    displayList(head);
    
    return 0;
}
