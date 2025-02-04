#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
}node;

node* createNode(int n){
    node * newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL){
        printf("Memory ALlocation failed");
        return NULL;
    }

    newNode->data = n;
    newNode->next = NULL;

    return newNode;
}

node* createList(node* head, int n){
    node* newNode = createNode(n);
    if(newNode == NULL){
        printf("Memory ALlocation failed");
        return NULL;
    }
    if(head == NULL){
        head = newNode;
        return head;
    }
    else{
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;

    }

    return head;
}

node * insertAtbegin(node* head, int value){
    node * newNode = createNode(value);

    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }

    return head;
}
node * insertAtEnd(node* head, int value){
    node * newNode = createNode(value);

    if(head == NULL){
        head = newNode;
    }
    else{
        node * temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

node * deleteBegin(node* head){
    if(head == NULL){
        
        printf("list is empty\n");
    }
    else{
        node* temp = head;
        head = temp->next;
        temp->next = NULL;
        free(temp);
    }

    return head;
}

node * deleteLast(node* head){
    if(head == NULL){
        
        printf("list is empty\n");
    }
    else{
        node* prev = NULL;
        node* temp = head;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);
        free(temp);
    }

    return head;
}

node * insertAtIndex(node* head, int value, int x){
    node * newNode = createNode(value);

    if(head ==  NULL){
        head = newNode;
    }
    else{
        if(x == 1){
            head = insertAtbegin(head, value);
        }
        else{
            node* temp = head;

            for(int i =1; i<x-1; i++){
                temp = temp->next;
            }
            if(temp == NULL){
                printf("invalid index");
                return head;
            }
            
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    return head;
}
node * deleteAtIndex(node* head,  int x){

    if(head == NULL){
        printf("list is empty");
        return NULL;
    }
    else{
        if(x == 1){
            head = deleteBegin(head);
        }
        else{
            node* temp = head;

            for(int i =1; i<x-1; i++){
                temp = temp->next;
            }
            if(temp == NULL || temp->next == NULL){
                printf("invalid index");
                return head;
            }
            node * remove = temp->next;
            temp->next = remove->next;
            free(remove);
        }
    }

    return head;
}
void display(node* head){
    if(head == NULL){
        printf("List is empty");
    }
    else{
        node* temp = head;
        while(temp != NULL){
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(){
    node* head = NULL;
    int n;
    // while(scanf("%d", &n) == 1){
    //     head = createList(head, n);
    //     if(getchar() == '\n') break;
    // }
    head = insertAtbegin(head, 4);
    head = insertAtbegin(head, 5);
    head = insertAtbegin(head, 54);
    head = insertAtEnd(head, 44);
    head = insertAtEnd(head, 84);
    head = insertAtIndex(head, 0, 1);
    // head = deleteBegin(head);
    // head = deleteBegin(head);
    // head = deleteLast(head);
    head = deleteAtIndex(head, 8);
    display(head);
    return 0;

}