class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> stk;

        vector<int> left(n, -1);
        for (int i = n - 1; i > -1; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                left[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        stack<int> stk2;
        vector<int> right(n, n);
        for (int i = 0; i < n; ++i) {
            while (!stk2.empty() && nums[stk2.top()] > nums[i]) {
                right[stk2.top()] = i;
                stk2.pop();
            }
            stk2.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (left[i] < k && right[i] > k)
                ans = max(ans, nums[i] * (right[i] - left[i] - 1));

        return ans;
    }

    int maximumScore_greedy(vector<int>& nums, int k) {
        int l = k, r = k;
        int ans = nums[k], wmin = nums[k];

        while (l > 0 || r + 1 < nums.size()) {
            if (l <= 0) {
                wmin = min(wmin, nums[++r]);
            } else if (r + 1 >= nums.size()) {
                wmin = min(wmin, nums[--l]);
            } else {
                if (nums[r + 1] < nums[l - 1]) {
                    wmin = min(wmin, nums[--l]);
                } else {
                    wmin = min(wmin, nums[++r]);
                }
            }

            int score = wmin * (r - l + 1);
            ans = max(ans, score);
        }


        return ans;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
