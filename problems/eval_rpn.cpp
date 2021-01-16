class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        int left;
        int right;
        
        for (int i=0; i<tokens.size(); ++i)
        {
            if ("+" == tokens[i])
            {
                right = s.top();
                s.pop();
                left = s.top();
                s.pop();
                s.push(left + right);
            }
            else if ("-" == tokens[i])
            {
                right = s.top();
                s.pop();
                left = s.top();
                s.pop();
                s.push(left - right);
            }
            else if ("*" == tokens[i])
            {
                right = s.top();
                s.pop();
                left = s.top();
                s.pop();
                s.push(left * right);
            }
            else if ("/" == tokens[i])
            {
                right = s.top();
                s.pop();
                left = s.top();
                s.pop();
                s.push(left / right);
            }
            else
            {
                s.push(std::stoi(tokens[i]));
            }
        }
        
        return s.top();
    }
};
