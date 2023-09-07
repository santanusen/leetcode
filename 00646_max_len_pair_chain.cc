class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b)->bool {
            return (a[1] < b[1]) || (a[1] == b[1] && a[0] < b[0]);
        });

        int ans = 1;
        for (int tail = pairs[0][1], j = 1; j < pairs.size(); ++j)
            if (tail < pairs[j][0]) {
                ++ans;
                tail = pairs[j][1];
            }
        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
