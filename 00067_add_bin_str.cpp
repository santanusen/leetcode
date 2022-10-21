class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int c  = 0;
        for (int i = a.length() - 1, j = b.length() - 1; i > -1 || j > -1 || c != 0; --i, --j) {
            char s = c;
            if (i > -1)
                s += (a[i] - '0');
            if (j > -1)
                s += (b[j] - '0');
            res += (s % 2 + '0');
            c = s / 2;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
}
