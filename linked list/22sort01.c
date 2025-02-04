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
    if(newNode == NULL) return NULL;

    if(head == NULL) return newNode;

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

node* display(node* head){
    node* temp = head;

    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

node* merge(node* zero, node* one, node* two){
    node* dummy = createNode(-1);
    node* temp = dummy;

    temp->next = zero;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = one;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = two;

    node* head = dummy->next;
    free(dummy);
    return head;

}
int main(){
    node* zero = NULL;
    node* one = NULL;
    node* two = NULL;
    int data;
    while(scanf("%d", &data)==1){
        if(data == 0){
            zero = createList(zero, data);
        }
        else if(data == 1){
            one = createList(one, data);
        }
        else{
            two = createList(two, data);
        }

        char c = getchar();
        if(c == '\n')break;
    }
    // display(zero);
    // display(one);
    // display(two);
    node* head = merge(zero, one, two);
    display(head);

}