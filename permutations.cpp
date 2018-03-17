#include <iostream>

using namespace std;

int permutations(string pre, string s)
{
    int ret = 0;
    
    if (s.size() == 1)
    {
        cout << pre + s << endl;
        return 1;
    }
    
    for (int i=0; i<s.size(); i++)
    {
        string tmp = s;
        tmp.erase(i, 1);
        ret += permutations(pre+s[i], tmp);
    }
    
    return ret;
}

int main() {
    string s = "abcd";
    
    cout << permutations("", s) << endl;
    
    return 0;
}
