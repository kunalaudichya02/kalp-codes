
// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
// bool has_cycle(SinglyLinkedListNode* head) {
//     if(head == NULL) return false;
//     SinglyLinkedListNode* ptr1 = head;
//     SinglyLinkedListNode* ptr2 = head;
    
//     while(ptr2 != NULL && ptr2->next != NULL){
//         ptr1 = ptr1->next;
//         ptr2 = ptr2->next->next;
        
//         if(ptr1 == ptr2){
//          return true;
//         }
//     }
//     return false;
// }