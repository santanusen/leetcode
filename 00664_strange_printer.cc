int dp [100][100];
int buf[100];
class Solution {
public:
   public:
    int strangePrinter(string s) {
        int n=s.size();
        const char * c=s.c_str();
        for(int a, b=0, i, k, m; b<n; ++b) {
            dp[b][b]=m=1;
            for(a=b-1, k=0; a>=0; --a) {
                if(c[a]!=c[b]) {
                    if(c[a+1]==c[b]) {
                        buf[k++]=a;
                    }
                    for(m=INT_MAX, i=0; i<k; ++i) {
                        m=min(m, dp[a][buf[i]]+dp[buf[i]+1][b]);
                    }
                }
                dp[a][b]=m;
            }
        }
        return dp[0][n-1];
    }
};

class Solution2 {
    int dfs(const string& s, int l, int r, vector<vector<int>>& dp) {
        if (dp[l][r] != -1) return dp[l][r];

        dp[l][r] = s.size();

        int j = -1;

        for (int i = l; i < r; ++i) {
            if (s[i] != s[r] && j == -1)
                j = i;

            if (j != -1)
                dp[l][r] = min(dp[l][r], 1 + dfs(s, j, i, dp) + dfs(s, i + 1, r, dp));
        }

        if (j == -1)
            dp[l][r] = 0;

        return dp[l][r];
    }

public:
    int strangePrinter(string s) {
        int n = s.size();

        int dp[n][n];
        for (int d = 1; d <= n; ++d) {
            for (int l = 0; l <= n - d; ++l) {
                int r = l + d - 1;
                dp[l][r] = n;
                int j = -1;

                for (int i = l; i < r; ++i) {
                    if (s[i] != s[r] && j == -1)
                        j = i;
                    if (j != -1)
                        dp[l][r] = min(dp[l][r], 1 + dp[j][i] + dp[i + 1][r]);
                }

                if (j == -1)
                    dp[l][r] = 0;
            }
        }

        return dp[0][n - 1] + 1;
    }

    int strangePrinter_dfs(string s) {
        int n = s.size();
        vector dp(n, vector<int>(n, -1));
        return dfs(s, 0, n - 1, dp) + 1;
    }
};

auto _=[](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();

