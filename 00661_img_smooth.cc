class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int M = img.size(), N = img[0].size();
        vector<vector<int>> ans(M, vector<int>(N));
        for (int r = 0; r < M; ++r) {
            for (int c = 0; c < N; ++c) {
                int sum = 0, count = 0;
                for (int x = r - 1; x < r + 2; ++x)
                    for (int y = c - 1; y < c + 2; ++y)
                        if (x > -1 && x < M && y > -1 && y < N) {
                            sum += img[x][y];
                            ++count;
                        }
                ans[r][c] = sum / count;
            }
        }

        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
