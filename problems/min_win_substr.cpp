class Solution {
public:
    string minWindow(string s, string t) {
        int bestStart = 0;
        int bestEnd = -1;
        int bestSublen = INT_MAX;
        int curCount = 0;
        int curStart = 0;
        int curEnd = 0;
        std::unordered_map<char, std::pair<int,int>> m;
        
        if (s == "" || t == "")
            return "";
        
        // Set up map
        for (int i=0; i<t.length(); ++i) {
            if (m.find(t[i]) == m.end())
                m.emplace(t[i], make_pair(0,1));
            else
                m[t[i]].second++;
        }
        
        // Iterate through s and expand curEnd
        for (curEnd=0; curEnd<s.length(); ++curEnd) {
//cout << "curEnd:" << curEnd << endl;
            //Increment curEnd
            if (m.find(s[curEnd]) != m.end()) {
                if (m[s[curEnd]].first < m[s[curEnd]].second)
                    curCount++;
                m[s[curEnd]].first++;
                int curSublen = curEnd-curStart+1;
                if (curCount == t.length() && curSublen < bestSublen) {
                    bestStart = curStart;
                    bestEnd = curEnd;
                    bestSublen = bestEnd-bestStart+1;
//cout << "set bestStart:" << bestStart << " bestEnd:" << bestEnd << endl;
                }
            }
            
            // Increment curStart
            while (curCount == t.length()) {
                if ((curEnd-curStart+1) < bestSublen) {
                    bestStart = curStart;
                    bestEnd = curEnd;
                    bestSublen = bestEnd-bestStart+1;
//cout << "set2 bestStart:" << bestStart << " bestEnd:" << bestEnd << endl;
                }
                
                if (m.find(s[curStart]) != m.end()) {
                    m[s[curStart]].first--;
                    if (m[s[curStart]].first < m[s[curStart]].second) {
                        curCount --;
                    }
                }
                curStart++;
            }
        }

//cout << "sublen:" << sublen << " t.length():" << t.length() << endl;
        if (bestEnd >= 0 && bestSublen >= t.length())
            return s.substr(bestStart, bestSublen);
                
        return "";
    }
};
