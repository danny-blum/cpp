class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> vret; 
        int slen = s.length();
        int nwords = words.size();
        if (slen==0 || nwords==0) return vret;
        int wlen = words[0].length();
        if (slen < wlen*nwords) return vret;
        vector<pair<int,int>> vword_starts(slen, make_pair(-1, 0));
    
        if (wlen == 0)
        {
            for (int i=0; i<=slen; i++)
                vret.push_back(i);
            return vret;
        }
        
        for (int i=0; i<slen; i++)
        {
            int pos = 0;
            for (int w=0; w<nwords; w++)
            {
                for (int j=i; j<i+wlen; j++)
                {
                    if (s[j] == words[w][pos])
                    {
                        pos++;
                    }
                    else
                    {
                        pos=0;
                        break;
                    }
                    if (pos == wlen)
                    {
                        vword_starts[i].first = w;
                        vword_starts[i].second++;
                        pos = 0;
                    }
                }
            }
        }
        
        for (int i=0; i<=slen-(nwords*wlen); i++)
        {
            if (vword_starts[i].first!=-1)
            {
                unordered_map<int, int> found_words;
                found_words[vword_starts[i].first] = 1;
                int j = i;
                bool found = true;
                for (int w=1; w<nwords; w++)
                {
                    j+= wlen;
                    if (vword_starts[j].first!=-1 && found_words.find(vword_starts[j].first)==found_words.end())
                    {
                        found_words[vword_starts[j].first] = 1;
                    }
                    else if (vword_starts[j].first!=-1 && found_words[vword_starts[j].first]<vword_starts[j].second)
                    {
                        found_words[vword_starts[j].first]++;
                    }
                    else
                    {
                        found = false;
                        break;
                    }
                }
                if (found)
                {
                    vret.push_back(i);
                }
            }
        }
        
        return vret;
    }
};
