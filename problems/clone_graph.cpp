/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        
        std::queue<Node*> q;
        q.push(node);
        std::unordered_map<int, Node*> cloned;
        
        Node *cloneHead = new Node(node->val);
        cloned[cloneHead->val] = cloneHead;
        
        while (!q.empty())
        {
            Node* cur = q.front();
            q.pop();
            
            for (int i=0; i<cur->neighbors.size(); ++i)
            {
                Node* nbor = cur->neighbors[i];
                Node *cloneNbor;
                if (cloned.find(nbor->val) == cloned.end())
                {
                    q.push(nbor);
                
                    cloneNbor = new Node(nbor->val);
                    cloned[cloneNbor->val] = cloneNbor;
                }
                else
                {
                    cloneNbor = cloned[nbor->val];
                }
                
                cloned[cur->val]->neighbors.push_back(cloneNbor);
            }
        }
        
        return cloneHead;
    }
};
