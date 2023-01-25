/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
auto printLinkedList(SinglyLinkedListNode* head) -> void {
    while(head) {
        std::cout << head->data << '\n';
        head = head->next;
    }
}