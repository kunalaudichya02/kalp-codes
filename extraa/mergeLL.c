#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} node;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL){
        printf("memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node* createList(node* head, int data){
    node* newNode = createNode(data);
    if(newNode == NULL){
        printf("memory allocation failed\n");
        return NULL;
    }
    if(head == NULL){
        return newNode;
    }

    node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

node* findMiddle(node* head){
    if (!head || !head->next) return head;
    node* slow = head;
    node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node* merge(node* left, node* right){

    node* t1 = left;
    node* t2 = right;
    node* dummy = createNode(-1);
    node* temp = dummy;

    while(t1 != NULL && t2 != NULL){
        if(t1->data <= t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }

    }

    while(t1!= NULL){
        temp->next = t1;
    }

    while(t2!= NULL){
         temp->next = t2;
    }
    return dummy->next;
}
node* mergeList(node* head){
    if(!head || !head->next) return head;
    node* middle = findMiddle(head);
    node* left = head;
    node* right = middle->next;
    middle->next = NULL;

    left = mergeList(left);
    right = mergeList(right);

    return merge(left, right);
}
void display(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp= temp->next;
    }
    printf("\n");
}
int main(){
    node* head = NULL;
    int data;
    while(scanf("%d", &data) == 1){
        head = createList(head, data);
        if(getchar() == '\n') break;
    }

    head = mergeList(head);
    display(head);
}
