/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
[[nodiscard]] auto height(Node* root) -> int {
    if (root == nullptr) return -1;
    
    auto leftHeight = int{height(root->left)};
    auto rightHeight = int{height(root->right)};
    
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}