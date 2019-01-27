class Solution {
public:
    double myPow(double x, int n) {
        if (x==0) return 0;
        if (n==0) return 1;
        if (n==1) return x;
        if (n==-1) return 1/x;
        if (n==INT_MIN) return myPow(x, INT_MIN+1) / x;
        
        double accum = x*x;
        int cur_pow = 2;
        
        int nabs = abs(n);
        while (cur_pow < nabs)
        {
            if (cur_pow <= (nabs-cur_pow))
            {
                accum *= accum;
                cur_pow += cur_pow;
            }
            else
            {
                accum = accum * myPow(x, nabs-cur_pow);
                cur_pow = nabs;
            }
        }
        
        if (n < 0)
            accum = 1/accum;
        
        return accum;
    }
};
