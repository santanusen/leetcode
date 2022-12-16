class Solution {
public:
    string longestPalindrome(string s) {
        string T = "^#";
        for (auto c : s) {
            T.push_back(c);
            T.push_back('#');
        }
        T.push_back('$');

        vector<int> P(T.length(), 0);
        int c = 0, r = 0, pmax = 0;
        for (int i = 1; i < T.length() - 1; ++i) {
            if (i < r) {
                //int mir = (c << 1) - i;
                P[i] = min(r - i, P[(c << 1) - i]);
            }

            while (T[i + P[i] + 1] == T[i - P[i] - 1])
                ++P[i];

            if (i + P[i] > r) {
                c = i;
                r = i + P[i];
            }
            if (P[i] > P[pmax]) pmax = i;
        }

        return s.substr((pmax - P[pmax]) >> 1, P[pmax]);
        
    }
};
