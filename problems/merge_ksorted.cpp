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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size())
            return NULL;
        
        ListNode *psorted = NULL;
        ListNode **ppcur = &psorted;
        
        initMap(lists);
        
        int min_idx = getMinIdx(lists);
        while(lists[min_idx])
        {
            *ppcur = lists[min_idx];
            ppcur = &((*ppcur)->next);

            removeListHead(lists, min_idx);
            min_idx = getMinIdx(lists);
        }
        
        
        return psorted;
    }
    
private:
    void initMap(vector<ListNode*>& lists) {
        for (int i=0; i<lists.size(); i++) {
            if (lists[i])
                idxMap.insert(std::pair<int,int>(lists[i]->val, i));
        }
    }
    
    void removeListHead(vector<ListNode*>& lists, int idx) {
        idxMap.erase(idxMap.find(lists[idx]->val));
        lists[idx] = lists[idx]->next;
        if (lists[idx])
            idxMap.insert(std::pair<int,int>(lists[idx]->val, idx));
    }
    
    int getMinIdx(vector<ListNode*>& lists) {
#if 0
        int min = INT_MAX;
        int min_idx = 0;
        for (int i=0; i<lists.size(); i++)
        {
            if (lists[i])
            {
                if (lists[i]->val < min)
                {
                    min = lists[i]->val;
                    min_idx = i;
                }
            }
        }
#endif
    
        int min_idx = 0;
        
        if (idxMap.size() > 0)
            min_idx = idxMap.begin()->second;
        
        return min_idx;
    }
    
    std::multimap<int, int> idxMap;
};
