class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int length = 1;
        int slen = beginWord.length();
        
        std::queue<pair<string,int>> qpaths;
        qpaths.push(make_pair(beginWord, 1));
        std::unordered_set<string> sWL;
        
        for (int i=0; i<wordList.size(); ++i)
            sWL.insert(wordList[i]);
        
        while(!qpaths.empty())
        {
            pair<string,int> ppath = qpaths.front();
            qpaths.pop();
            int curlen = ppath.second;
            string path = ppath.first;
            string ns;
            
            if (curlen > length)
            {
                length = curlen;  
            }
            
            for (int i=0; i<slen; ++i)
            {
                ns = path;
                for (char c='a'; c<='z'; ++c)
                {
                    ns[i] = c;
                    if (sWL.find(ns) != sWL.end())
                    {
                        if (ns == endWord)
                        {
                            length++;
                            return length;
                        }
                        else
                        {
                            qpaths.push(make_pair(ns,length+1));
                            sWL.erase(ns);
                        }
                    }
                }
            }
        }

        return 0;
    }
};
