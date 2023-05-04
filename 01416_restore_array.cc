class Solution {
    const int MOD = 1E9 + 7;

    int dfs(const string& s, int k, int i, vector<int>& DP) {
        if (i == s.length()) return 1;
        if (s[i] == '0') return 0;
        if (DP[i] != -1) return DP[i];

        long long int num = 0;
        int count = 0;
        for (int j = i; j < s.length(); ++j) {
            num = 10 * num + (s[j] - '0');
            if (num > k) break;
            count += dfs(s, k, j + 1, DP);
            count %= MOD;
        }

        return (DP[i] = count);

    }

public:
    int numberOfArrays(string s, int k) {
        //vector<int> DP(s.length(), -1);
        //return dfs(s, k, 0, DP);

        //if (s[0] == '0') return 0;

        int n = s.length();
        int DP[n + 1];
        DP[n] = 1;
        for (int i = n - 1; i > -1; --i) {
            DP[i] = 0;
            if (s[i] != '0') {
                long long int num = 0;
                for (int j = i; j < n; ++j) {
                    num = num * 10 + (s[j] - '0');
                    if (num > k) break;
                    DP[i] = (DP[i] + DP[j + 1]) % MOD;
                }
            }
        }

        return DP[0];
    }
};
