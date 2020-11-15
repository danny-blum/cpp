/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head)
            return;
        int size = countNodes(head);

        if (size < 3)
            return;
        
        if (size >= 4)
            reverseSecondHalf(head, size);
        
        interleaveNodes(head, size);
    }
private:
    int countNodes(ListNode* head) {
        ListNode* cur = head;
        int size = 0;
        
        while (cur)
        {
            size++;
            cur = cur->next;
        }
        
        return size;
    }
    
    void reverseSecondHalf(ListNode* head, int size) {
        ListNode* n1 = head;
        ListNode* n2;
        ListNode* n3;
        ListNode* n3_next;
        int mid = (size-1) / 2;
        
        for (int i=0; i<mid; ++i)
            n1 = n1->next;
        
        n2 = n1->next;
        n3 = n2->next;
        n2->next = NULL;
        
        while (n3)
        {
            n3_next = n3->next;
            n3->next = n2;
            
            n2 = n3;
            n3 = n3_next;
        }
        
        n1->next = n2;
    }
    
    void interleaveNodes(ListNode* head, int size) {
        ListNode* n1 = head;
        ListNode* n1_next = head->next;
        ListNode* n2 = head;
        int mid = (size+1) / 2;
        
        for (int i=0; i<mid; ++i)
            n2 = n2->next;

        ListNode* n2_next = n2->next;
        
        for (int i=0; i<mid; ++i)
        {
            n1->next = n2;
            if (n2_next)
                n2->next = n1_next;
            else
                break;
            
            n1 = n1_next;
            n1_next = n1->next;
            n2 = n2_next;
            n2_next = n2->next;
        }
        
        if (size % 2)
        {
            n2->next = n1_next;
            n2->next->next = NULL;
        }
        else
            n2->next = NULL;        
    }
};
