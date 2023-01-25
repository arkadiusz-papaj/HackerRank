

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
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

[[nodiscard]] auto insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) -> SinglyLinkedListNode* {
    if (llist == nullptr) {
        llist = new SinglyLinkedListNode(data);
    }

    auto current_node = llist;
    auto new_node = new SinglyLinkedListNode(data);
    
    if (position == 0) {
        new_node->next = current_node;
        llist = new_node;
    }
    else {
        while (position > 1){
            if (current_node->next == nullptr) {
                current_node->next = new SinglyLinkedListNode(data);
            }
            current_node = current_node->next;
            position--;
        }
        
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
    
    return llist;
}