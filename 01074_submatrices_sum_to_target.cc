class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i)
            for(int j = 1; j < n; ++j)
                matrix[i][j] += matrix[i][j - 1];

        int ans = 0;                
        unordered_map<int, int> count;
        for (int cb = 0; cb < n; ++cb) {
            for (int ce = cb; ce < n; ++ce) {
                count = {{0, 1}};
                int csum = 0;
                for (int r = 0; r < m; ++r) {
                    csum += matrix[r][ce];
                    if (cb > 0)
                        csum -= matrix[r][cb - 1];
                    auto itr = count.find(csum - target);
                    if (itr != count.end())
                        ans += itr->second;
                    ++count[csum];
                }
            }
        }

        return ans;
    }

    int numSubmatrixSumTarget_brute(vector<vector<int>>& matrix, int target) {
        int ans = 0;

        for (int x = 0, y = 0; x < matrix.size(); ) {

            for (int imax = x; imax < matrix.size(); ++imax)
                for (int jmax = y; jmax < matrix[0].size(); ++jmax) {
                    int sum = 0;
                    for (int i = x; i <= imax; ++i)
                        for (int j = y; j <= jmax; ++j)
                            sum += matrix[i][j];
                    if (sum == target)
                        ++ans;
                }
            if (++y == matrix[0].size()) {
                ++x;
                y = 0;
            }
        }

        return ans;
        
    }
};
