class Solution {
public:
    
    inline int GetSymVal (char ch) {

        switch (ch) {
                case 'I':
                        return 1;
                case 'V':
                        return 5;
                case 'X':
                        return 10;
                case 'L':
                        return 50;
                case 'C':
                        return 100;
                case 'D':
                        return 500;
                case 'M':
                        return 1000;

                default:
                        return 0;
        }
    }

    
    int romanToInt(const string& s) {
        int val = 0;
        int pval = INT_MAX;

        for (int i = 0; i < s.length(); ++i) {
                int cval = GetSymVal(s.at(i));     
                if (cval > pval) {
                        val -= 2 * pval;
                }
                val += cval;
                pval = cval;
        }

        return val;
    }
};
