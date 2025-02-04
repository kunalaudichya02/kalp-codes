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
    if( head == NULL){
        printf("List is empty\n");
        return ;
    }
    node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

node* merge(node* left, node* right){

    node* t1 = left;
    node* t2 = right;
    node* dummy = createNode(-1);
    node* temp = dummy;

    while(t1 != NULL && t2 != NULL){
        if(t1->data <= t2->data){
            temp->next = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            t2 = t2->next;
        }
        temp = temp->next;
    }

    while(t1!= NULL){
        temp->next = t1;
        t1 = t1->next;
        temp = temp->next;
    }

    while(t2!= NULL){
         temp->next = t2;
         t2 = t2->next;
         temp = temp->next;
    }
    node* newHead = dummy->next;
    free(dummy);
    //  printf("%d\n", newHead->data);
    return newHead;
}
int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    int data;
    while(scanf("%d",&data)==1){
        head1 = createList(head1, data);
        if(getchar() == '\n'){
            break;
        }
    }

    while(scanf("%d",&data)==1){
        head2 = createList(head2, data);
        if(getchar() == '\n'){
            break;
        }
    }
    // printf("hey\n");

    node* newhead = merge(head1, head2);
    // printf("%d\n", newhead->data);
    printf("hey\n");
    display(newhead);
}