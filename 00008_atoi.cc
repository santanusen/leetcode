class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, base = 0, i = 0;
        while (str[i] == ' ') i++;
        if (str[i] == '-' || str[i] == '+')
            sign = 1 - 2 * (str[i++] == '-');
        
        while (str[i] >= '0' && str[i] <= '9') {
            if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            base  = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
    
    int myAtoi2(string s) {
        
        enum state_t {BEGIN, SIGN, NUM, END} st = BEGIN;
        
        bool neg = false;
        
        int res = 0;
        
        for (auto c : s) {
            switch (st) {
                case BEGIN:
                    if (isdigit(c)) {
                        res = c - '0';
                        st = NUM;
                    } else if (c == '+') {
                        st = SIGN;
                    } else if (c == '-') {
                        neg = true;
                        st = SIGN;
                    } else if (c != ' ') {
                        st = END;
                    }
                    break;
                    
                case SIGN:
                    if (isdigit(c)) {
                        res = ((neg) ? -(c - '0') : c - '0');
                        st = NUM;
                    } else {
                        st = END;
                    }
                    break;
                    
                case NUM:
                    if (isdigit(c)) {
                        int d = c - '0';
                        if (!neg) {
                            static int max_d_10 = INT_MAX / 10;
                            static int max_m_10 = INT_MAX % 10;
                            if (res > max_d_10 || (res == max_d_10 && d >= max_m_10)) {
                                res = INT_MAX;
                                st = END;
                            } else {
                                res = 10 * res + d;
                            }
                        } else {
                            static int min_d_10 = INT_MIN / 10;
                            static int min_m_10 = INT_MIN % 10;
                            if (res < min_d_10 || (res == min_d_10 && -d <= min_m_10)) {
                                res = INT_MIN;
                                st = END;
                            } else {
                                res = 10 * res - d;
                            }
                        }
                    } else {
                        st = END;
                    }
                    break;
                    
                case END:
                    break;
                    
            }
        }
        
        return res;
        
    }
};
