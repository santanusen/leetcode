class Solution {
    public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0;
        int l = 0, r = 0;

        int t = 0, f = 0;
        while (r < answerKey.size()) {
            if (answerKey[r++] == 'T')
                ++t;
            else
                ++f;

            if (min(t, f) <= k) {
                ans = max(ans, r - l);
            } else {
                while (min(t, f) > k && l < r) {
                    if (answerKey[l++] == 'T')
                        --t;
                    else
                        --f;
                }
            }
        }

        return ans;
    }
};

class Solution_MLE_TLE {
    int dfs(string& ans, int pos, int k, char tgt, vector<vector<int>>& memo) {
        if (k == 0 || pos == ans.size()) {
            int cmax = 0, cs = 0;
            for (auto c : ans) {
                if (c == tgt)
                    cmax = max(cmax, ++cs);
                else
                    cs = 0;
            }
            return cmax;
        }

        if (memo[pos][k] != -1)
            return memo[pos][k];

        auto retain = dfs(ans, pos + 1, k, tgt, memo);
        auto flip = 0;
        if (ans[pos] != tgt) {
            char tmp = ans[pos];
            ans[pos] = tgt;
            flip = dfs(ans, pos + 1, k - 1, tgt, memo);
            ans[pos] = tmp;
        }

        return memo[pos][k] = max(retain, flip);
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        vector<vector<int>> tmemo(answerKey.size(), vector<int>(k + 1, -1));
        auto fmemo = tmemo;
        auto t = dfs(answerKey, 0, k, 'T', tmemo);
        auto f = dfs(answerKey, 0, k, 'F', fmemo);

        return max(t, f); 
    }
};
