#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char name[50];
    struct Node* next;
} node;

node* createNode(char * name){
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}


node* createList(node* head, char* name){
    node* newNode = createNode(name);
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
    if(head == NULL) return;
    node* temp = head;
    while(temp!= NULL){
        printf("%s ", temp->name);
        temp = temp->next;
    }

}


node* removelastK(node* head, int k){
    if(head == NULL || head->next == NULL) return head;
    node* a = head;
    node* b = head;
    node* prev = NULL;

    for(int i=0; i<k; i++){
        b = b->next;
    }

    while(b!= NULL){
        prev = a;
        a = a->next;
        b = b->next;
    }

    prev->next = a->next;
    free(a);
    return head;
}
int main(){
    node* head = NULL;
    char name[50];
    while(scanf("%s", name)==1){
        head = createList(head, name);
        char c = getchar();
        if(c == '\n')break;
    }

    int k;
    scanf("%d", &k);
    head = removelastK(head, k);
    display(head);

}