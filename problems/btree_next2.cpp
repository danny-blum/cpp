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
        if (!root) return NULL;
        
        connectSub(root, true);
        
        return root;
    }
    
private:
    void connectSub(Node* cur, bool rightmost) {
        Node *next_parent;
        
        if (cur->left) {
            if (cur->right)
                cur->left->next = cur->right;
            else {
                next_parent = cur->next;
                while (next_parent) {
                    if (next_parent->left) {
                        cur->left->next = next_parent->left;
                        break;
                    }
                    else if (next_parent->right) {
                        cur->left->next = next_parent->right;
                        break;
                    }
                    
                    next_parent = next_parent->next;
                }
            }
        }
     
        if (cur->right) {
            if (!rightmost) {
                next_parent = cur->next;
                while (next_parent) {
                    if (next_parent->left) {
                        cur->right->next = next_parent->left;
                        break;
                    }
                    else if (next_parent->right) {
                        cur->right->next = next_parent->right;
                        break;
                    }
                    
                    next_parent = next_parent->next;
                } 
            }
        }
        
        if (cur->right)
            connectSub(cur->right, rightmost);
        if (cur->left)
            connectSub(cur->left, false);
    }
};
