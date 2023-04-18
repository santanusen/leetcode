class Solution {


    long long dfs(const string& tgt, int i, int j, vector<vector<int>>& freq, vector<vector<long long>>& memo) {
        if (j == 0)
            return (i == 0) ? 1 : 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        const int MOD = 1E9 + 7;

        auto res = dfs(tgt, i, j - 1, freq, memo);
        if (i > 0)
            res += freq[tgt[i - 1] - 'a'][j - 1] * dfs(tgt, i - 1, j - 1, freq, memo);
        res %= MOD;
        memo[i][j] = res;
        return res;
    }

public:
    int numWays(vector<string>& words, string target) {

        int k = words[0].size();

        vector freq(26, vector<int>(k, 0));
        for (int l = 0; l < k; ++l)
            for (auto& w : words)
                ++freq[w[l] - 'a'][l];

        vector memo(target.size() + 1, vector<long long>(k + 1, -1));
        return dfs(target, target.size(), k, freq, memo);
    }
};
