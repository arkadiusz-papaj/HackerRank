/*
 * Complete the 'removeDuplicates' function below.
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

[[nodiscard]] auto removeDuplicates(SinglyLinkedListNode* llist) -> SinglyLinkedListNode* {
    if (llist == nullptr) return llist;
    
    auto worker = llist->next;
    auto memo = llist;
    
    while (worker != nullptr) {
        while (worker->data == memo->data) {
            memo->next = worker->next;
            delete worker;
            if (memo->next != nullptr) worker = memo->next;
            else return llist;
        }

        worker = worker->next;
        memo = memo->next;
    }
    
    return llist;
}