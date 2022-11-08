class Solution {
public:
    string makeGood(string s) {
        //const int BAD = 'a' - 'A';
        for (int i = 0; i + 1 < s.length();) {
            if (abs(s[i] - s[i + 1]) == 32) {
                s.erase(i, 2);
                i = max(0, i - 1); // i needs to point to the previous char: abBA -> aA
            } else
                ++i;
        }
        
        return s;
    }
};
