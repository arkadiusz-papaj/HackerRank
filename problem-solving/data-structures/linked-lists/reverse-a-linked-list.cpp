/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

[[nodiscard]] auto reverse(SinglyLinkedListNode* llist) -> SinglyLinkedListNode* {
    //recursively
    // if (llist == nullptr || llist->next == nullptr) {
    //     return llist;
    // }

    // auto reversed_head = reverse(llist->next);
    // llist->next->next = llist; //node AFTER me, point back at me
    // llist->next = nullptr; //destroy my connection to next node (already pointing at me)
    
    // return reversed_head;
    
    //iteratively
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* next = current->next;
    
    if (current == nullptr) {
        return llist;
    }
    
    while (next != nullptr) {
        current->next = prev;
        
        prev = current;
        current = next;
        next = next->next;
    }
    
    current->next = prev;
    
    return current;
}