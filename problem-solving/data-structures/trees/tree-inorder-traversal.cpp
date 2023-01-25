/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

auto inOrder(Node *root) -> void {
    if (root == nullptr) return;
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}