class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        if (0 == size)
            return -1;
        
        int maxSum = 0;
        int maxStart = 0;
        int curSum = 0;
        int curStart = 0;
        int totalSum = 0;
        
        for (int i=0; i<size; ++i) {
            int diff = gas[i] - cost[i];
            totalSum += diff;
            
            if (curSum <= 0) {
                curStart = i;
                curSum = 0;
            }
            
            curSum += diff;
            if (curSum > maxSum) {
                maxSum = curSum;
                maxStart = curStart;
            }
        }
        
        if (totalSum < 0)
            return -1;
        
        // Check wrap-around for new maxSum
        for (int i=0; i<curStart; ++i) {
            int diff = gas[i] - cost[i];
        
            if (curSum <= 0)
                break;
            
            curSum += diff;
            if (curSum > maxSum) {
                maxSum = curSum;
                maxStart = curStart;
            }
        }
        
        return maxStart;
    }
};
