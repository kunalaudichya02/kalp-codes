#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char id[7];
    int count;
    struct Node * next;
}node;

node* createNode(char * id){
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->id, id);
    newNode->count= 1;
    newNode->next = NULL;

    return newNode;
}

node* createList(node* head, char * id){
    node* newNode = createNode(id);
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
    node* temp = head;
    while(temp){
        printf("%s ", temp->id);
        temp = temp->next;
    }
    printf("\n");
}

void findCommon(node* head1, node* head2){
    node* t1 = head1;
    node* t2 = head2;

    while(t1 != NULL){
        while(t2 != NULL){
            if(strcmp(t1->id, t2->id)==0){
                // t1->count++;
                t2->count++;
                printf("%s ", t1->id);
            }
            t2 = t2->next;
        }
        t2 = head2;
        t1= t1->next;
    }
    t1 = head1;
}

void findUnique(node* head1, node* head2){
    node* t1 = head1;
    node* t2 = head2;
    printf("\n unique: ");
    while(t1!= NULL){
        printf("%s ", t1->id);
        t1 = t1->next;
    }
    while(t2!= NULL){
        if(t2->count == 1){
            printf("%s ", t2->id);
        }
        t2 = t2->next;
    }
}
int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    char id[7];
    while(scanf("%s", id)==1){
        head1 = createList(head1, id);
        char c = getchar();
        if(c == '\n') break;
    }
    while(scanf("%s", id)==1){
        head2 = createList(head2, id);
        char c = getchar();
        if(c == '\n') break;
    }
    findCommon(head1, head2);
    findUnique(head1, head2);
    // display(head1);
    // display(head2);
    return 0;
}