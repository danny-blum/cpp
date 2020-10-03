/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        
        std::unordered_map<Node*, Node*> orig2Copy;
        
        Node* copyHead = new Node(head->val);
        copyHead->random = head->random;
        orig2Copy[head] = copyHead;
        
        Node* origCur = head;
        Node* copyCur = copyHead;
        Node* copyNext;
        
        while (origCur->next)
        {
            copyNext = new Node(origCur->next->val);
            copyNext->random = origCur->next->random;
            orig2Copy[origCur->next] = copyNext;
            copyCur->next = copyNext;
            
            copyCur = copyNext;
            origCur = origCur->next;
        }
        
        copyCur = copyHead;
        while (copyCur)
        {
            if (copyCur->random)
                copyCur->random = orig2Copy[copyCur->random];
            copyCur = copyCur->next;
        }
        
        return copyHead;
    }
};
