class Solution {
public:
    
    string add(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        int carry = 0;
        int place;
        
        if (len1 > len2)
        {
            int diff = len1 - len2;
            string pad(diff, '0');
            num2 = pad + num2;
            len2 = len1;
        }
        else if (len2 > len1)
        {
            int diff = len2 - len1;
            string pad(diff, '0');
            num1 = pad + num1;
            len1 = len2;
        }
        
        string sum(len1, '0');
        for (int i=len1-1; i>=0; i--)
        {
            place = (num1[i]-'0') + (num2[i]-'0') + carry;
            carry = place / 10;
            place %= 10;
            sum[i] = (char)(place+'0');
        }
        
        if (carry)
            sum = '1' + sum;
        
        return sum;
    }
    
    string multiply(string num1, string num2) {
        string product;
        int place;
        int carry;
        
        if (num1=="" || num2=="" || num1=="0" || num2=="0")
            return "0";
        
        for (int i=num2.length()-1; i>=0; i--)
        {
            string tmp(num2.length()-i-1, '0');
            carry = 0;
            for (int j=num1.length()-1; j>=0; j--)
            {
                place = (num1[j]-'0')*(num2[i]-'0') + carry;

                carry = place / 10;
                place %= 10; 
                tmp = (char)(place + '0') + tmp; 
            }
            if (carry)
                tmp = (char)(carry + '0') + tmp;
            product = add(product, tmp);
        }
        
        return product;
    }
};
