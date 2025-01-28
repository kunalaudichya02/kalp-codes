#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node ;

node* insertAtEnd(node* head, int a){
    node * newNode = (node*)malloc(sizeof(node));
    if(head == NULL){
        
        newNode->data = a;
        newNode->next = NULL;
        head = newNode;
    }
    else{
        node*temp = head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->data = a;
        newNode->next = NULL;
    }
    return head;
}
node* insertAtBegin(node* head, int a){
    if(head == NULL){
        insertAtBegin(head, a);
    }
    else{
        node * newNode = (node*)malloc(sizeof(node));
        newNode->data = a;
        newNode->next = head;
        head = newNode;

    }
    return head;
}
node* insertAtIndex(node* head, int a, int b){
     node * newNode = (node*)malloc(sizeof(node));
    newNode->data = a;
    newNode->next = NULL;

    if(b==1){
       head = insertAtBegin(head, a);
       return head;
    }
    else{
        node * temp = head;
        for(int i=1; i<b-1; i++){
            if (temp == NULL) {  // Out-of-bounds check
            printf("Invalid position\n");
            free(newNode);
            return head;
        }
            temp = temp->next;
        }
        if (temp == NULL) {  // Out-of-bounds check
            printf("Invalid position\n");
            free(newNode);
            return head;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}
node* updateAtIndex(node* head, int a, int b){
    node*temp = head;
    for(int i=1; i<b; i++){
            if (temp == NULL) {  // Out-of-bounds check
            printf("Invalid position\n");
            return head;
        }
            temp = temp->next;
        }
         if (temp == NULL) {  // Out-of-bounds check
            printf("Invalid position\n");
            return head;
         }
         temp->data = a;
return head;
}
node* deleteLast(node* head){
    node * temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}
node* deleteFirst(node* head){
    node*temp = head;
    head = temp->next;
    free(temp);
    return head;
}
node* deleteAtIndex(node* head, int a){
    node*temp = head;
    if(a==1){
        head = deleteFirst(head);
        return head;
    }
    for(int i=1; i<a-1; i++){
        if(temp==NULL || temp->next==NULL){
            printf("Invalid index");
            return head;
        }
        temp = temp->next;
    }
      if(temp->next==NULL){
            printf("Invalid index");
            return head;
        }
    node * remove = temp->next;
    temp->next = remove->next;
    remove->next = NULL;
    free(remove);
    return head;
}
node* display(node* head){
    if(head == NULL){
        printf("list is empty");
    }
    node* temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return head;
}

int main(){
    node * head = NULL;
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 6);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 7);
    head = deleteAtIndex(head, 6);
    // head = updateAtIndex(head, 1, 4);
    // head = insertAtBegin(head, 6);
    display(head);
    // int n;
    // scanf("%d", &n);

/*
    for(int i=1; i<=n; i++){
        int x;
        scanf("%d", &x);

        switch(x){
            case 1:{
                int a;
                scanf("%d", &a);
                head = insertAtEnd(head, a);
            }
            break;
            
            case 2:{
                int a;
                scanf("%d", &a);
                head = insertAtBegin(head, a);
            }
            break;

            case 3:{
                int a, b;
                scanf("%d %d", &a, &b);
                head = insertAtIndex(head, a, b);
            }
            break;

            case 4:
                head = display(head);
            break;

            case 5:{
                int a, b;
                scanf("%d %d", &a, &b);
                head = updateAtIndex(head, a, b);
            }
            break;

            case 6:
                head = deleteFirst(head);
            break;

            case 7:
                head = deleteLast(head);
            break;

            case 8:{
                int a;
                scanf("%d", &a);
                head = deleteAtIndex(head, a);
                display(head);
            }
            break;
        }
    }
*/
    return 0;
}