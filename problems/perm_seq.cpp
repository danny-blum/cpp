class Solution {
public:
    
    void calcPerm(int pos, int ncur, int kcur, string scur, string &sret, int fact)
    {
        if (ncur == 0) return;
        if (scur == "") return;
        int n = ncur;
        
        for (pos=0; pos<n; ++pos)
        {
            int next_fact = fact / ncur;
            int index = (kcur-1) / next_fact;
            char digit = scur[index];

            sret[pos] = digit;
            string snext(ncur-1, ' ');
            int j=0;

            for (int i=0; i<ncur; ++i)
            {
                if (scur[i] != digit)
                    snext[j++] = scur[i];
            }
            
            ncur--;
            kcur = (kcur-1)%next_fact + 1;
            fact = next_fact;
            scur = snext;
        }
    }
    
    string getPermutation(int n, int k) {
        string sret(n, ' ');
        string sfirst(n, ' ');
        int fact = 1;
        for (int i=1; i<=n; ++i)
        {
            sfirst[i-1] = (char)i + '0';
            fact *= i;
        }
        
        calcPerm(0, n, k, sfirst, sret, fact);
        
        return sret;
    }
};
