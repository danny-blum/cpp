class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size <= 1)
            return size;
        int i;
        vector<int> candies(size, 1);
        
        for (i=0; i<size; ++i)
        {
            if (i>0 && ratings[i]>ratings[i-1])
            {
                candies[i] = candies[i-1]+1;
            }
            if (i<(size-1) && ratings[i]>ratings[i+1])
            {
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        
        int total = candies[size-1];
        for (i=size-2; i>=0; --i)
        { 
            if (ratings[i]>ratings[i+1])
            {
                candies[i] = max(candies[i], candies[i+1]+1);
            }
            total += candies[i];
        }
        
        return total;
    }
};
