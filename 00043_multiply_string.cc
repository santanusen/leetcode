class Solution {
    string str_add(const string& s1, const string& s2) {
        string res;
        for (int i = s1.length() - 1, j = s2.length() - 1, carry = 0;
             i > -1 || j > -1 || carry;) {
            int sum = carry;
            if (i > -1) sum += (s1[i--] - '0');
            if (j > -1) sum += (s2[j--] - '0');
            carry = sum / 10;
            sum %= 10;
            res.push_back(sum + '0');
        }    
        if (res.empty()) return "0";
        reverse(res.begin(), res.end());
        return res;
    }

    string str_sub(const string& s1, const string& s2) {
        string res;
        for (int i = s1.length() - 1, j = s2.length() - 1, carry = 0;
             i > -1 || j > -1 || carry;) {
            int d1 = (i > -1) ? (s1[i--] - '0') : 0;
            int d2 = carry + ((j > -1) ? (s2[j--] - '0') : 0);

            if (d2 > d1) {
                d1 += 10;
                carry = 1;
            } else
                carry = 0;
            res.push_back(d1 - d2 + '0');
        }    
        if (res.empty()) return "0";
        reverse(res.begin(), res.end());
        return res;
    }
    

    string str_mult_digit(const string& s1, char s2) {
        if (s1 == "0" || s2 == '0') return "0";
        string res;
        for (int i = s1.length() - 1, carry = 0, d = s2 - '0';
             i > -1 || carry;) {
            int sum = carry;
            if (i > -1) sum += ((s1[i--] - '0') * d);
            carry = sum / 10;
            sum %= 10;
            res.push_back(sum + '0');
        }    
        if (res.empty()) return "0";
        reverse(res.begin(), res.end());
        return res;
    }

    string karatsuba(const string& s1, const string& s2) {
        if (s1.length() == 1)
            return to_string(int((s1[0] - '0') * (s2[0] - '0')));

        int n = s1.length() / 2;
        string a = s1.substr(0, n), b = s1.substr(n);
        string c = s2.substr(0, n), d = s2.substr(n);
        string p = str_add(a, b), q = str_add(c, d);

        string ac = karatsuba(a, c), bd = karatsuba(b, d), pq = karatsuba(p, q);
        string adbc = str_sub(str_sub(pq, ac), bd);

        return str_add(str_add(ac + string(2 * (s1.length() - n), '0'), adbc + string(n, '0')), bd);
    }

public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string res;
        for (auto d : num2) {
            res.push_back('0');
            res = str_add(res, str_mult_digit(num1, d));
        }
        return res;
    }

    string multiply_karatsuba(string num1, string num2) {
        if (num1.length() < num2.length()) {
            num1 = string(num2.length() - num1.length(), '0') + num1;
        } else if (num2.length() < num1.length()) {
            num2 = string(num1.length() - num2.length(), '0') + num2;
        }
        return karatsuba(num1, num2);
    }
};
