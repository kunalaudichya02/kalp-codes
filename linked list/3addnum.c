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
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node* findSum(node* head1, node* head2){
    int carry = 0;
    node* head = NULL;
    while(head1 != NULL && head2 != NULL ){
        int data = carry + (head1->data + head2->data);
        carry = data/10;
        head = createList(head, data%10);
        head1 = head1->next;
        head2 = head2->next;
    }

    while(head1){
        head = createList(head, head1->data);
        head1 = head1->next;
    }
    while(head2){
        head = createList(head, head2->data);
        head2 = head2->next;
    }

    return head;
}

int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    int data;
    while(scanf("%d", &data)==1){
        head1 = createList(head1, data);
        if(getchar()=='\n') break;
    }
    while(scanf("%d", &data)==1){
        head2 = createList(head2, data);
        if(getchar()=='\n') break;
    }
    
    node* sum = findSum(head1, head2);
    display(sum);
    return 0;
}