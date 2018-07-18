class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        int rem = x;
        int pow2 = 1;
        
        while (rem >= 4)
        {
            rem >>= 2;
            pow2 *= 2;
        }
        
        int max = x / pow2;
        
        return search(x, pow2, max);
    }
    
private:
    int search(int x, int min, int max)
    {
        if (max-min <= 1) return min;
        int mid = (max-min)/2 + min;
        
        int div = x / mid;
        if (div == mid) return mid;
        if (div > mid)
            return search(x, mid, div);
        return search(x, div, mid);
    }
};
