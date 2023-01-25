/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts INTEGER_DOUBLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

[[nodiscard]] auto reverse(DoublyLinkedListNode* llist) -> DoublyLinkedListNode* {
    if (llist == nullptr) return nullptr;
    
    DoublyLinkedListNode* helper = nullptr;
    while (llist->next != nullptr) {
        llist->prev = llist->next;
        llist->next = helper;
        helper = llist;
        llist = llist->prev;
    }
    
    llist->prev = llist->next;
    llist->next = helper;
    
    return llist;
}