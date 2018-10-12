class Solution {
public:
    int divide(int dividend, int divisor) {
        long long udividend;
        long long udivisor;
        int quotient = 0;
        int multiple;
        bool neg = false;
        
        if (divisor == 0) return -1;
        if (dividend==INT_MIN && divisor==1) return INT_MIN;
        if (dividend==INT_MIN && divisor==-1) return INT_MAX;        
        
        if (dividend < 0)
        {
            neg = true;
        }
        if (divisor < 0)
        {
            neg = !neg;
        }
        udividend = labs(dividend);
        udivisor = labs(divisor);
        
        multiple = 1;
        while ((udivisor<<1) <= udividend)
        {
            udivisor <<= 1;
            multiple <<= 1;
        }
    
        while (multiple)
        {
            if (udivisor <= udividend)
            {
                udividend -= udivisor;
                quotient += multiple;
            }
            udivisor >>= 1;
            multiple >>= 1;
        }
        
        if (neg)
            quotient = 0 - quotient;
        
        return quotient;
    }
};
