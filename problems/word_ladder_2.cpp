class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> vvladder;
        int wsize = beginWord.length();
        unordered_set<string> swl;
        queue<vector<string>> qpaths;
        int level = 1;
        int minLevel = INT_MAX;
        unordered_set<string> svisited;
        
        qpaths.push({beginWord});
        for (int i=0; i<wordList.size(); ++i)
        {
            swl.insert(wordList[i]);
        }

        while(!qpaths.empty())
        {
            vector<string> path = qpaths.front();
            qpaths.pop();
            if (path.size() > level)
            {
                unordered_set<string>::iterator sviter;
                for (sviter=svisited.begin(); sviter!=svisited.end(); ++sviter)
                    swl.erase(*sviter);
                
                svisited.clear();
                if (path.size() > minLevel)
                    break;
                else
                    level = path.size();
            }
            string last = path.back();
            for (int i=0; i<last.length(); ++i)
            {
                string ns = last;
                for (char c='a'; c<='z'; ++c)
                {
                    ns[i] = c;
                    if (swl.find(ns) != swl.end())
                    {
                        vector<string> npath = path;
                        npath.push_back(ns);
                        svisited.insert(ns);
                        if (ns == endWord)
                        {
                            minLevel = level;
                            vvladder.push_back(npath);
                        }
                        else
                        {
                            qpaths.push(npath);
                            
                        }
                    }
                }
            }
        }

        return vvladder;
    }
};
