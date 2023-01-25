#include <cassert>

/*
 * Complete the 'getNode' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER positionFromTail
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

[[nodiscard]] auto getNode(SinglyLinkedListNode* llist, int positionFromTail) -> int {
    assert(positionFromTail >= 0);

    auto offset = unsigned{0};
    auto lead_ptr = llist;
    auto follower_ptr = llist;
    
    while (lead_ptr->next != nullptr) {
        lead_ptr = lead_ptr->next;
        if (offset < positionFromTail) {
            offset++; //count "distance" until positionFromTail
        }
        else {
            follower_ptr = follower_ptr->next; //then keep moving follower
        }  
    }
    
    return follower_ptr->data;
}

