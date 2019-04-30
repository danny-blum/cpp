class Solution {
public:
    
    enum states_e {
        LEAD_WS,
        LEAD_DIG,
        NEXT_DIG_PT_E,
        NEXT_DEC_DIG_E,
        FIRST_E_DIG_PM,
        FIRST_E_DIG,
        NEXT_E_DIG,
        TRAIL_WS
    };
    
    bool isNumber(string s) {
        states_e cur_state = LEAD_WS;
        states_e next_state = LEAD_WS;
        bool done = false;
        bool digit = false;
        int i = 0;
        int len = s.length();
        
        while (!done)
        {
            switch (cur_state)
            {
                case LEAD_WS:
                    if (i == len) return false;
                    else if (s[i] == ' ') next_state = LEAD_WS;
                    else if (s[i]=='+' || s[i]=='-') next_state = LEAD_DIG;
                    else if (isdigit(s[i])) {digit = true; next_state = NEXT_DIG_PT_E;}
                    else if (s[i] == '.') next_state = NEXT_DEC_DIG_E;
                    else return false;
                    break;
                case LEAD_DIG:
                    if (i == len) return false;
                    else if (isdigit(s[i])) {digit = true; next_state = NEXT_DIG_PT_E;}
                    else if (s[i] == '.') next_state = NEXT_DEC_DIG_E;
                    else return false;
                    break;
                case NEXT_DIG_PT_E:
                    if (i == len) 
                        if (digit) return true;
                        else return false;
                    else if (isdigit(s[i])) next_state = NEXT_DIG_PT_E;
                    else if (s[i] == '.') next_state = NEXT_DEC_DIG_E;
                    else if (s[i] == 'e') next_state = FIRST_E_DIG_PM;
                    else if (s[i] == ' ') next_state = TRAIL_WS;
                    else return false;
                    break;             
                case NEXT_DEC_DIG_E:
                    if (i==len)
                        if (digit) return true;
                        else return false;
                    else if (isdigit(s[i])) {digit = true; next_state = NEXT_DEC_DIG_E;}
                    else if (s[i] == 'e') next_state = FIRST_E_DIG_PM;
                    else if (s[i] == ' ') next_state = TRAIL_WS;
                    else return false;
                    break;
                case FIRST_E_DIG_PM:
                    if (i == len) return false;
                    else if (s[i]=='+' || s[i]=='-') next_state = FIRST_E_DIG;
                    else if (isdigit(s[i])) next_state = NEXT_E_DIG;
                    else return false;
                    break;
                case FIRST_E_DIG:
                    if (i == len) return false;
                    else if (isdigit(s[i])) next_state = NEXT_E_DIG;
                    else return false;
                    break;
                case NEXT_E_DIG:
                    if (i == len) 
                        if (digit) return true;
                        else return false;
                    else if (isdigit(s[i])) next_state = NEXT_E_DIG;
                    else if (s[i] == ' ') next_state = TRAIL_WS;
                    else return false;
                    break;
                case TRAIL_WS:
                    if (i == len) 
                        if (digit) return true;
                        else return false;
                    else if (s[i] == ' ') next_state = TRAIL_WS;
                    else return false;
                    break; 
            }
            i++;
            cur_state = next_state;
        }
        
        return false;
    }
};
