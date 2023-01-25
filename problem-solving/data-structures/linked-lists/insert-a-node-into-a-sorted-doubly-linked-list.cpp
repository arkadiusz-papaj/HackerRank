/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
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

[[nodiscard]] auto sortedInsert(DoublyLinkedListNode* llist, int data) -> DoublyLinkedListNode* {
    auto worker = llist;
    
    while(worker->data < data && worker->next != nullptr){
        worker = worker->next; 
    }
    
    auto new_node = new DoublyLinkedListNode(data);

    if (worker == llist) {
        worker->prev = new_node;
        new_node->next = worker;
        llist = new_node;
    }
    else if (worker->data < data && worker->next == nullptr) {
        new_node->prev = worker;
        worker->next = new_node;
    }
    else {
        new_node->next = worker;
        new_node->prev = worker->prev;
    
        new_node->prev->next = new_node;
        worker->prev = new_node;
    }

    return llist;
}