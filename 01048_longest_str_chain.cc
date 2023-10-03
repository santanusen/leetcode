class Solution {
    bool isSubseq(const string& s, const string& t) {
        int n = s.length(), pos = 0;

        for (auto ch : t)
            if (ch == s[pos] && ++pos == n)
                return true;

        return false;
    }

public:
    int longestStrChain(vector<string>& words) {
        map<int, vector<pair<string, int>>> dp;
        for (auto& w : words)
            dp[w.length()].push_back({w, 1});

        int ans = 1;

        for (auto pitr = dp.begin(), itr = ++dp.begin(); itr != dp.end(); ++itr, ++pitr) {
            if (itr->first != pitr->first + 1)
                continue;

            for (auto& [w, chn] : itr->second) {
                for (auto& [pw, pchn] : pitr->second) {
                    if (pchn + 1 > chn && isSubseq(pw, w)) {
                        chn = pchn + 1;
                        ans = max(ans, chn);
                    }
                }
            }
        }

        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
