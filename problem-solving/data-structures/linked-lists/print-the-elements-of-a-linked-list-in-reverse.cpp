/*
 * Complete the 'reversePrint' function below.
 *
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

auto reversePrint(SinglyLinkedListNode* llist) -> void {
    if (llist->next != nullptr) {
        reversePrint(llist->next);
    }
    
    std::cout << llist->data << '\n';
    
    return;   
}