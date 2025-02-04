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

void display(node* head){
    node* temp = head;

    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

node* reverse(node* head){
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    while(current!= NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
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
    return newHead;
}

node* reverseKth(node* head, int k){

    node* temp = head;
    node* newHead = NULL;
    node* prevEnd = NULL;
    while(temp != NULL){
        node* start = temp;
        node* prev = NULL;
        for(int i=0; i<k && temp!= NULL; i++){
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        node* reversed = reverse(start);

        if(newHead == NULL){
            newHead = reversed;
        }
        else{
            prevEnd->next = reversed;
        }

        prevEnd = start;


    }

    return newHead;
}
int main(){
    node* head = NULL;
    int data;
    while(scanf("%d", &data)==1){
        head = createList(head, data);
        char c = getchar();
        if(c == '\n') break;
    }
    int k;
    scanf("%d", &k);

    head = reverseKth(head, k);
    display(head);
}