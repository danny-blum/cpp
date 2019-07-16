class Solution {
public:
    string minWindow(string s, string t) {
        std::list<char> l;
        std::map<char, std::pair<int, std::list<char>::iterator>> m;
        int firstCur = -1;
        int lastCur = -1;
        int firstBest = -1;
        int lastBest = -1;
        int sublenBest = INT_MAX;
        int charsFound = 0;
        
        if (s.length() == 0 || t.length() == 0)
            return "";
        
        for (int i=0; i<t.length(); ++i)
            m.emplace(t[i], make_pair(-1, l.end()));
            
        for (int i=0; i<s.length(); ++i) {
//cout << "s[" << i << "]:" << s[i] << endl;
            if (m.find(s[i]) != m.end()) {
                if (m[s[i]].first == -1) {    // just found this char
                    std::list<char>::iterator lit = l.insert(l.end(), s[i]);
                    m[s[i]].first = i;
                    m[s[i]].second = lit;
                    if (firstCur == -1) {
                        firstCur = i;
//cout << "firstCur:" << firstCur << endl;
                    }
                    charsFound++;
                    if (charsFound == t.size()) {
                        lastCur = i;
                        int sublen = lastCur - firstCur + 1;
                        if (sublen == t.length())
                            return (s.substr(firstCur, lastCur-firstCur+1));   // early return of optimum substr
                        if (sublen < sublenBest) {
                            firstBest = firstCur;
                            lastBest = lastCur;
                            sublenBest = sublen;
                        }
                        m[*l.begin()].first = -1;     // kick out first
                        l.erase(l.begin());
                        firstCur = m[*l.begin()].first;
//cout << "kick out and replaced firstCur:" << firstCur << endl;
                        charsFound--;    
                    } 
                }
                else {                     // update char pos
                    m[s[i]].first = i;
                    if (m[s[i]].second == l.begin()) {
                        if (l.size() > 1)
                            firstCur = m[*(++l.begin())].first;
                        else
                            firstCur = i;
//cout << "update firstCur:" << firstCur << endl;
                    }
                    l.erase(m[s[i]].second);
                    std::list<char>::iterator lit = l.insert(l.end(), s[i]);
                    m[s[i]].second = lit;
                }
            } // if (m.find(s[i]) != m.end())
        } // for (int i=0; i<s.length(); ++i)
        
//cout << "firstBest:" << firstBest << " lastBest:" << lastBest << endl;
        if (sublenBest <= s.length())
            return s.substr(firstBest, lastBest-firstBest+1);
                
        return "";
    }
};
