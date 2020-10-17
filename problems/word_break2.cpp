class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> sentences;
        if (0 == s.length())
            return sentences;
        if (0 == wordDict.size())
            return sentences;
        
        vector<bool> checked(s.length(), false);
        
        wordBreakSub(s, wordDict, sentences, checked, 0);
        
        return sentences;
    }
    
private:
    bool wordBreakSub(string s,
                      vector<string>& wordDict,
                      vector<string> &sentences,
                      vector<bool> &checked,
                      int idx) {
        if (idx == s.length())
        {
            sentences.push_back("");
            return true;
        }
        
        if (checked[idx])
            return false;
        
        bool ret = false;
        for (int i=0; i<wordDict.size(); ++i)
        {
            string sdict = wordDict[i];
            if (0 == s.compare(idx, sdict.length(), sdict))
            {
                int curNumSentances = sentences.size();
                if (wordBreakSub(s, wordDict, sentences, checked, idx+sdict.length()))
                {
                    for (int j=curNumSentances; j<sentences.size(); ++j)
                    {
                        string cur = sentences[j];
                        if (cur != "")
                            cur = sdict + " " + cur;
                        else
                            cur = sdict;
                        sentences[j] = cur;

                        ret = true;
                    }
                }
            }
        }
        
        if (!ret)
            checked[idx] = true;
        return ret;
    }
};
