class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> vret;
        string line;
        int wCount = 0;
        int wLenCur = 0;
        int wstart = 0;
        
        for (int i=0; i<words.size(); ++i)
        {
            string word = words[i];
            int wlen = word.length();
            
            if (wLenCur == 0)
            {
                if (wlen > maxWidth) return vret;
                wstart = i;
                wCount = 1;
                wLenCur = wlen;
            }
            else
            {
                if (wlen+1 > maxWidth-wLenCur)
                {
                    justify(wstart, i-1, wLenCur, maxWidth, words, line, false);
                    vret.push_back(line);
                    line.clear();
                    if (wlen > maxWidth) return vret;
                    wstart = i;
                    wCount = 1;
                    wLenCur = wlen;
                }
                else
                {
                    wCount++;
                    wLenCur += wlen+1;
                }   
            }
        }
        
        justify(wstart, words.size()-1, wLenCur, maxWidth, words, line, true);
        vret.push_back(line);
        
        return vret;
    }

private:
    void justify(int start, int end, int wLenCur, int maxWidth, vector<string> &words, string &line, bool lastLine)
    {
        int nwords = end - start + 1;
        int pad = maxWidth - wLenCur;
        int padPerWord;
        int padRem;
        
        if (!lastLine && nwords>1)
        {
            padPerWord = pad / (nwords-1);
            padRem = pad % (nwords-1);
        }
        else
        {
            padPerWord = 0;
            padRem = pad;
        }
        
        for (int i=start; i<end; ++i)
        {
            line += words[i];
            int space = 1 + padPerWord;
            if (!lastLine && padRem)
            {
                space++;
                padRem--;
            }
            line += string(space, ' ');
        }
        line += words[end];
        
        line += string(padRem, ' ');
    }
};
