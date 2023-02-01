class Solution {
    bool divides(const string& num, const string &den) {
        if (num.length() % den.length()) return false;
        for (int i = 0; i < num.length(); i += den.length())
            if (num.compare(i, den.length(), den) != 0)
                return false;

        return true;
    }

public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1) ? str1.substr(0, gcd(str1.length(), str2.length())) : "";
    }

    string gcdOfStrings2(string str1, string str2) {
        const string& den = (str1.length() < str2.length()) ? str1 : str2;
        const string& num = (&den == &str1) ? str2 : str1;

        int n = den.length();
        for (int l = n, div = 2; l > 0; l = n / div, ++div) {
            auto gcd = den.substr(0, l);
            if (divides(num, gcd) && divides(den, gcd))
                return gcd;
        }

        return "";
    }
};
