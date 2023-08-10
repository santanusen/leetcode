class Solution {
    int dfs(vector<int>& boxes, int l, int r, int k, vector<vector<vector<int>>>& memo) {
        if (l > r) return 0;
        if (l == r) return (k + 1) * (k + 1);

        if (memo[l][r][k]) return memo[l][r][k];

        int res = (k + 1) * (k + 1) + dfs(boxes, l + 1, r, 0, memo);
        for (int m = l + 1; m <= r; ++m)
            if (boxes[l] == boxes[m])
                res = max(res, dfs(boxes, l + 1, m - 1, 0, memo) +
                               dfs(boxes, m, r, k + 1, memo));

        return memo[l][r][k] = res;

    }

    int dfs2(vector<int>& boxes, int l, int r, int k, vector<vector<vector<int>>>& memo) {
        if (l > r) return 0;

        if (memo[l][r][k]) return memo[l][r][k];

        int x = l, z = k;
        while (x < r && boxes[x + 1] == boxes[x]) {
            ++x;
            ++z;
        }

        int res = (z + 1) * (z + 1) + dfs(boxes, x + 1, r, 0, memo);
        for (int m = x + 1; m <= r; ++m)
            if (boxes[x] == boxes[m])
                res = max(res, dfs(boxes, x + 1, m - 1, 0, memo) +
                               dfs(boxes, m, r, z + 1, memo));

        return memo[l][r][k] = res;

    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> memo(n, vector(n, vector<int>(n)));
        return dfs(boxes, 0, n - 1, 0, memo);
    }
};
