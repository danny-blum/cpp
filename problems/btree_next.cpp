/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root)
            connectSub(root, true);
        
        return root;
    }
private:
    void connectSub(Node* node, bool rightEdge) {
        if (!node->left || !node->right)
            return;
        
        node->left->next = node->right;
        
        if (!rightEdge) {
            node->right->next = node->next->left;
        }
        
        connectSub(node->left, false);
        connectSub(node->right, rightEdge);
    }
    
};
