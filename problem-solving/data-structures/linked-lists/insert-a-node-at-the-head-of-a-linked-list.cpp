// Complete the insertNodeAtHead function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
[[nodiscard]] auto insertNodeAtHead(SinglyLinkedListNode* llist, int data) -> SinglyLinkedListNode* {
	auto new_head = new SinglyLinkedListNode(data);
    new_head->next = llist;
    return new_head;
}