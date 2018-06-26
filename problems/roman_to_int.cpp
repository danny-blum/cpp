class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        
        for (int i=0; i<s.length(); ++i)
        {
            bool last = (i == (s.length()-1));
            switch (s[i])
            {
                case ('I'):
                {
                    if (!last && s[i+1]=='V')
                    {
                        res += 4;
                        i++;
                    }
                    else if (!last && s[i+1]=='X')
                    {
                        res += 9;
                        i++;
                    }
                    else
                    {
                        res += 1;
                    }
                    break;
                }
                case ('V'):
                {
                    res += 5;
                    break;
                }
                case ('X'):
                {
                    if (!last && s[i+1]=='L')
                    {
                        res += 40;
                        i++;
                    }
                    else if (!last && s[i+1]=='C')
                    {
                        res += 90;
                        i++;
                    }
                    else
                    {
                        res += 10;
                    }
                    break;
                }
                case ('L'):
                {
                    res += 50;
                    break;
                }
                case ('C'):
                {
                    if (!last && s[i+1]=='D')
                    {
                        res += 400;
                        i++;
                    }
                    else if (!last && s[i+1]=='M')
                    {
                        res += 900;
                        i++;
                    }
                    else
                    {
                        res += 100;
                    }
                    break;
                }
                case ('D'):
                {
                    res += 500;
                    break;
                }
                case ('M'):
                {
                    res += 1000;
                    break;
                }
                default:
                    return 0;
                    break;
            }            
        }
        
        return res;
    }
};
