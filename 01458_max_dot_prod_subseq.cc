class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
        for (auto num : nums1) {
            max1 = max(max1, num);
            min1 = min(min1, num);
        }

        for (auto num : nums2) {
            max2 = max(max2, num);
            min2 = min(min2, num);
        }

        if (max1 < 0 && min2 > 0)
            return max1 * min2;

        if (max2 < 0 && min1 > 0)
            return max2 * min1;

        int m = nums1.size(), n = nums2.size();
        vector dp (m + 1, vector(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i + 1][j + 1] =
                max({
                    dp[i + 1][j],
                    dp[i][j + 1],
                    nums1[i] * nums2[j] + dp[i][j]
                });
            }
        }

        return dp[m][n];
        
    }
};
