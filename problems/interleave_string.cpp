class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1len = s1.length();
        int s2len = s2.length();
        int s3len = s3.length();
        
        if ((s1len + s2len) != s3len)
            return false;
        if (s3len == 0)
            return true;
            
//        return isInterleaveSub(s1, 0, s2, 0, s3, 0);
        
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<bool>> visited(s1len+1, std::vector<bool>(s2len+1, false));
        q.push(make_pair(0,0));
        
        while (!q.empty()) {
            std::pair p = q.front();
            q.pop();

            if (p.first==s1len && p.second==s2len)
                return true;
            
            if (visited[p.first][p.second])
                continue;
            
            if (p.first<s1len && s1[p.first]==s3[p.first+p.second]) {
                q.push(make_pair(p.first+1, p.second));
            }
            if (p.second<s2len && s2[p.second]==s3[p.first+p.second]) {
                q.push(make_pair(p.first, p.second+1));
            }
            visited[p.first][p.second] = true;
        }
        
        return false;
    }

    
/*
    bool isInterleaveSub(string s1, int idx1, string s2, int idx2, string s3, int idx3) {
        std::stack<std::pair<int, int>> stk;
        while (idx3 < s3.length()) {
            bool s1End = (idx1 >= s1.length());
            bool s2End = (idx2 >= s2.length());
            if (!s1End && !s2End && s1[idx1]==s3[idx3] && s2[idx2]==s3[idx3]) {

//                if (isInterleaveSub(s1, idx1+1, s2, idx2, s3, idx3+1))
//                    return true;
//                else return isInterleaveSub(s1, idx1, s2, idx2+1, s3, idx3+1);

                stk.push(make_pair(idx1, idx2));
                idx1++;
            }
            else if (!s1End && s1[idx1]==s3[idx3])
                idx1++;
            else if (!s2End && s2[idx2]==s3[idx3])
                idx2++;
            else {
                if (stk.empty())
                    return false;
                std::pair p = stk.top();
                stk.pop();
                idx1 = p.first;
                idx2 = p.second;
                idx3 = idx1 + idx2;
                idx2++;
            }
            
            idx3++;
        }
        
        return true;
    }
*/
};
