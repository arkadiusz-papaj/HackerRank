// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
[[nodiscard]] auto insertNodeAtTail(SinglyLinkedListNode* head, int data) -> SinglyLinkedListNode* {
    if (head == nullptr) {
        head = new SinglyLinkedListNode(data);
    }
    else {
        auto current_node = head;

        while(current_node->next != nullptr){
            current_node = current_node->next;
        }

        current_node->next = new SinglyLinkedListNode(data);
    }

    return head; 
}