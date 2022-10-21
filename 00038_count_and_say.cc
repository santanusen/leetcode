class Solution {
public:
    string say(string num) {
        char dprev = '\0';
        int count = 0;
        string res;
        
        num += '$';
        for (auto d : num) {
            if (d != dprev) {
                if (count > 0)
                    res += (to_string(count) + dprev);
                count = 1;
                dprev = d;
            } else
                ++count;
        }
        return res;
    }

    string countAndSay(int n) {
        if (n == 1)
                return "1";
        return say(countAndSay(n - 1));
    }
};
