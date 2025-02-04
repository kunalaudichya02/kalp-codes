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

node* oddEven(node* head){
    node* current = head;
    node* oddhead = NULL;
    node* evenhead = NULL;
    node* oddtail = NULL;
    node* eventail = NULL;

    while(current!= NULL){
        if(current->data % 2 == 0){
            if(evenhead==NULL){
                evenhead = current;
                eventail = current;
            }
            else{
                eventail->next = current;
                eventail = current;
            }
        }
        else{
            if(oddhead==NULL){
                oddhead= current;
                oddtail= current;
            }
            else{
                oddtail->next = current;
                oddtail = current;
            }
        }
        current = current->next;
    }
    if(eventail!=  NULL){
        eventail->next = oddhead;
    }
    if(oddtail!= NULL){
        oddtail->next = NULL;
    }
    // node* odd = head;
    // node* even = head;

    // while((odd->data)%2 != 1){
    //     odd = odd->next;
    // }
    // while((even->data)%2 != 0){
    //     even = even->next;
    // }
    // node* temp = even;
    // node* e= even;
    // while(e!= NULL){
    //     if((e->data)%2 != 0){
    //         e = e->next;
    //     }
    //     even->next = e;
    //     even = even->next;
    // }
    // even->next = odd;

    // node* o= odd;
    // while(o!= NULL){
    //     if((o->data)%2 != 0){
    //         o = o->next;
    //     }
    //     odd->next = o;
    //     odd = odd->next;
    // }

    return evenhead;
}

int main(){
    node * head = NULL;
    int data;
    while(scanf("%d", &data)==1){
        head = createList(head, data);
        if(getchar()=='\n')break;
    }

    node* temp = oddEven(head);
    display(temp);
    return 0;
}