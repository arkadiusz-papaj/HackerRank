// Complete the compare_lists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
[[nodiscard]] auto compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) -> bool {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data != head2->data) {
            return false;
        }
        
        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1 == nullptr && head2 == nullptr) return true;
    else return false;
}