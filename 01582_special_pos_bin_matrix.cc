class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0, m = mat.size(), n = mat[0].size();
        vector<int> rsum(m), csum(n), cidx(m);
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 1) {
                    ++rsum[r];
                    ++csum[c];
                    cidx[r] = c;
                }
            }

        for (int r = 0; r < m; ++r) {
            int c = cidx[r];
            if (mat[r][c] == 1 && rsum[r] == 1 && csum[c] == 1)
                ++ans;
        }
        
        return ans;
    }

    int numSpecial1(vector<vector<int>>& mat) {
        int ans = 0, m = mat.size(), n = mat[0].size();
        vector<int> rsum(m), csum(n);
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 1) {
                    ++rsum[r];
                    ++csum[c];
                }
            }

        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (mat[r][c] == 1 && rsum[r] == 1 && csum[c] == 1)
                    ++ans;
        
        return ans;
    }

    int numSpecial2(vector<vector<int>>& mat) {
        int ans = 0, m = mat.size(), n = mat[0].size();
        for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c)
            if (mat[r][c] == 1) {
                bool spl = true;

                for (int i = 0; i < m && spl; ++i)
                    if (mat[i][c] == 1 && i != r)
                        spl = false;

                for (int j = 0; j < n && spl; ++j)
                    if (mat[r][j] == 1 && j != c)
                        spl = false;

                if (spl) ++ans;
            }
        
        return ans;
        
    }
};

//auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
