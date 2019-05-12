class Solution {
public:
    string simplifyPath(string path) {
        std::deque<string> dq;
        stringstream ss(path);
        string tok;
        string sret;
        
        while(getline(ss, tok, '/'))
        {
            if (tok=="." || tok=="")
            {    // do nothing
            }
            else if (tok == "..")
            {
                if (!dq.empty()) dq.pop_back();
            }
            else
                dq.push_back(tok);
        }
        
        if (dq.empty()) sret = "/";
        while(!dq.empty())
        {
            tok = dq.front();
            dq.pop_front();
            sret += "/" + tok;
        }
        
        return sret;
    }
};
