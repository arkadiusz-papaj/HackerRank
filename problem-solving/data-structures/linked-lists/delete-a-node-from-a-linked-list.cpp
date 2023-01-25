/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
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

[[nodiscard]] auto deleteNode(SinglyLinkedListNode* llist, int position) -> SinglyLinkedListNode* {
    auto current_node = llist;
    SinglyLinkedListNode* node_to_delete = nullptr;
        
    if (position == 0) {
        node_to_delete = llist;
        current_node = llist->next;
        
        delete node_to_delete;
        node_to_delete = nullptr;
        
        llist = current_node;
    }
    else {
        while (position > 1) {
            current_node = current_node->next;
            position--;
        }
        node_to_delete = current_node->next;
        current_node->next = node_to_delete->next;
        
        delete node_to_delete;
        node_to_delete = nullptr;
    }
    
    return llist;
}