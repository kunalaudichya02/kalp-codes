#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char id[7];
    struct Node* next;
    int flag;
} node;

node* createNode (char *id){
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->id, id);
    newNode->flag = 1;
    newNode->next = NULL;

    return newNode;
}

node* createList(node* head, char * id){
    node* newNode = createNode(id);
    if(newNode == NULL){
        return NULL;
    }
    if(head == NULL){
        head = newNode;
        head->next = head;
        return head;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

void display(node* head){
    if(head == NULL){
        return ;
    }
    node* temp = head;
    do{
        printf("%s ", temp->id);
        temp = temp->next;
    }while(temp!= head);

}

int length(node* head){
    node* temp = head;
    int count=0;
    while(temp!= head){
        temp = temp->next;
        count++;
    }
    return count;
}
node* circularGame(node* head, int k, int count){
    node* temp = head;
    // node* prev = NULL;

    // while(temp->next!= temp ){
    //     for(int i=0; i<k-1; i++){
    //         prev = temp;
    //         temp = temp->next;
    //     }
    //     prev->next = temp->next;
    //     free(temp);
    //     temp = prev->next;
    // }

    while(count!= 1){
         for(int i=0; i<k-1; i++){
            if(temp->flag==0){
                i--;
            }
            temp = temp->next;
        }
        temp->flag = 0;
        count--;
    }

    return temp;
}

int main(){
    node* head = NULL;
    char id[7];
    while(scanf("%s", id)==1){
        head = createList(head, id);
        char c = getchar();
        if(c=='\n')break;
    }
    int k;
    scanf("%d", &k);
    int len = length(head);
    node* temp = circularGame(head, k, len);
    display(temp);
}