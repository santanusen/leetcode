class Solution {
    bool ispal(const string& s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--]) return false;
        return true;
    }

    void dfs(const string& s, int pos, vector<string>& path, vector<vector<string>>& res) {
        if (pos == s.length()) {
            res.push_back(path);
            return;
        }

        for (int i = pos; i < s.length(); ++i) {
            if (ispal(s, pos, i)) {
                path.push_back(s.substr(pos, i - pos + 1));
                dfs(s, i + 1, path, res);
                path.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }

    vector<vector<string>> partition_dp(string s) {
        vector<vector<vector<string>>> dp(s.length() + 1);
        dp[0] = vector<vector<string>> (1, vector<string>());
        // dp -> vvv
        // dp[x] -> vv
        // y : dp[x] -> v
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j > -1; --j) {
                if (ispal(s, j, i)) {
                    string ps = s.substr(j, i - j + 1);
                    for (auto v : dp[j]) {
                        v.push_back(ps);
                        dp[i + 1].push_back(v);
                    }
                }
            }
        }
        return dp[s.length()];
    }
};
