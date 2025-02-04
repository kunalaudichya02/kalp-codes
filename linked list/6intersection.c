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

int length(node* head){
    node* temp = head;
    int count = 0;
    while(temp!= NULL){
        temp = temp->next;
        count++;
    }

    return count;
}
node* intersection(node* head1, node* head2){
    int len1 = length(head1);
    int len2 = length(head2);
    node* t1 = head1;
    node* t2 = head2;
    int diff;
    if(len1 < len2){
        diff = len2-len1;
        while(diff!= 0){
            t2 = t2->next;
            diff--;
        }
    }
    else{
        diff = len1 - len2;
         while(diff!= 0){
            t1 = t1->next;
            diff--;
        }
    }

    while(t1 != NULL && t2 != NULL){

        if(t1 == t2){
            return t1;
        }
        t1 = t1->next;
        t2= t2->next;

    }
    if(t1 == NULL && t2 == NULL){
        return NULL;
    }
    return NULL;
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

    node* inter = intersection(head1, head2);
    if(inter){
        printf("%d\n", inter->data);
    }
    else{
        printf("No intersection point\n");
    }
    
}