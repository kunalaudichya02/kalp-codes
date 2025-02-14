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

node* sort(node* head){
    node* temp1 = head;
    node* temp2 = head;
    int swapped=1;
    while(swapped){
        swapped=0;
        temp2= temp1->next;
        while(temp2!= NULL){
            int x, y;
            if(temp1->data <0){
                x = temp1->data * -1;
            }
            if(temp2->data <0){
                y = temp2->data * -1;
            }
            if(y < x){
                int value = temp1->data;
                temp1->data = temp2->data;
                temp2->data = value; 
                swapped=1;
            }
            temp2 = temp2->next;
        }
        temp1=temp1->next;
    }

return head;
}
int main(){
    node* head = NULL;
    int data;
    while(scanf("%d", &data)==1){
        head = createList(head, data);
        char c = getchar();
        if(c == '\n') break;
    }

    head = sort(head);
    display(head);
}