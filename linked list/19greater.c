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
    while(temp->next){
        temp= temp->next;
    }

    temp->next = newNode;
    return head;
}

void display(node* head){
    if(head == NULL){
        return;
    }
    node* temp = head;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


node* removeSmaller(node* head){

    node* dummy = createNode(-1);
    node* prev = dummy;
    node* current = head;

    while(current!= NULL && current->next != NULL){
        node* next = current->next;

        if(next->data > current->data){
            prev->next = next;
            free(current);
            current = next;
        }
        else{
            prev = current;
            current = current->next;
        }

    }
    head = dummy->next;
    free(dummy);
    return head;

}
int main(){
    node * head = NULL;
    int data;
    while(scanf("%d", &data)==1){
        head = createList(head, data);
        if(getchar()=='\n')break;
    }

    node* temp = removeSmaller(head);
    display(temp);
    return 0;
}