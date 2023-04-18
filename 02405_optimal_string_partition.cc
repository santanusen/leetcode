class Solution {
public:
    int partitionString(string s) {
        unsigned cmap = 0;
        int ans = 1;
        for (auto ch : s) {
            unsigned mask = 1 << (ch - 'a');
            if (cmap & mask) {
                ++ans;
                cmap = 0;
            }
            cmap |= mask;
        }
        return ans;
    }

    int partitionString_greedy(string s) {
        int ans = 1;
        int lastseen[26];
        for (auto& ls : lastseen) ls = -1;

        for (int i = 0, subs = 0; i < s.size(); ++i) {
            if (lastseen[s[i] - 'a'] >= subs) {
                ++ans;
                subs = i;
            }
            lastseen[s[i] - 'a'] = i;
        }
        return ans;
    }

    int partitionString_arr(string s) {
        int ans = 1;
        bool hset[26] = {false};
        for (auto ch : s) {
            if (hset[ch - 'a']) {
                ++ans;
                memset(hset, 0, sizeof(hset));
            }
            hset[ch - 'a'] = true;
        }
        return ans;
    }

    int partitionString_hset(string s) {
        int ans = 1;
        unordered_set<char> hset;
        for (auto ch : s)
            if (!hset.insert(ch).second) {
                ++ans;
                hset = {ch};
            }
        return ans;
    }
};
