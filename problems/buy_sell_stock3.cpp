class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int psize = prices.size();
        int firstBuy = INT_MIN;
        int firstSell = 0;
        int secondBuy = INT_MIN;
        int secondSell = 0;
        
        for (int i=0; i<psize; ++i)
        {
            secondSell = std::max(secondSell, prices[i] + secondBuy);
            secondBuy = std::max(secondBuy, firstSell - prices[i]);
            firstSell = std::max(firstSell, prices[i] + firstBuy);
            firstBuy = std::max(firstBuy, -1 * prices[i]);
        }
        
        return secondSell;
    }
};
