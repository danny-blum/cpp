/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return NULL;
        
        ListNode *cycleNode = findCycle(head);
        if (!cycleNode)
            return NULL;
        
        int cycleCount = findCycleCount(cycleNode);
        if (cycleCount == 1)
            return cycleNode;
            
        // Separate p1 and p2 by the size of the cycle
        ListNode *p1 = head;
        ListNode *p2 = head;
        for (int i=0; i<cycleCount; ++i)
            p2 = p2->next;
        
        // Advance p1 and p2 until they wrap around the
        // cycle and point to the starting node
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
    }
    
private:
    ListNode *findCycle(ListNode *head) {
        if (!head)
            return NULL;
        
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        while (p1->next && p2->next && p2->next->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            
            if (p1 == p2)
                return p1;
        }
        
        return NULL;
    }
    
    int findCycleCount(ListNode *node) {
        int count = 1;
        ListNode *p1 = node->next;
        
        while (p1 != node)
        {
            count++;
            p1 = p1->next;
        }
        
        return count;
    }
};
