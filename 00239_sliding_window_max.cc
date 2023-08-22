class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        deque<int> dq;
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); ++i) {
            if (dq.front() == i - k)
                dq.pop_front();

            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }

    vector<int> maxSlidingWindow_pq(vector<int>& nums, int k) {
        vector<int> ans;

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k - 1; ++i)
            pq.push({nums[i], i});

        for (int i = k - 1; i < nums.size(); ++i) {
            int j = i - k + 1;
            pq.push({nums[i], i});
            while (pq.top().second < j)
                pq.pop();
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
