static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> nums;
        for (int i = 0; i < nums2.size(); ++i)
            nums.push_back({nums2[i], nums1[i]});
        sort(nums.begin(), nums.end(), greater<pair<int, int>>());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i].second;
            pq.push(nums[i].second);
        }

        long long ans = sum * nums[k - 1].first;
        for (int i = k; i < nums.size(); ++i) {
            if (pq.top() < nums[i].second) {
                sum += (nums[i].second - pq.top());
                pq.pop();
                pq.push(nums[i].second);
                ans = max(ans, sum * nums[i].first);
            }
        }

        return ans;
    }
};
