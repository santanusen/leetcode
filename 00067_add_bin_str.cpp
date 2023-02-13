class Solution {
public:
    string addBinary2(string a, string b) {
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

    string addBinary(string a, string b) {
        string c(max(a.size(), b.size()) + 1, '0');
        int i = a.size() - 1, j = b.size() - 1, k = c.size() - 1;
        int car = 0;
        while (car || i > -1 || j > -1) {
            int sum = car;
            if (i > -1) sum += (a[i--] - '0');
            if (j > -1) sum += (b[j--] - '0');
            car = sum / 2;
            c[k--] = sum % 2 + '0';
        }
        return (c[0] == '0') ? c.substr(1) : c;
    }
}
