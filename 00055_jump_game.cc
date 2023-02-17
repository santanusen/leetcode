class Solution {
public:
    bool canJump(vector<int>& arr) {
        int end=0, maxi = 0, n = arr.size();
        for (int i = 0; i < n; ++i) {
            maxi = max (maxi, i + arr[i]);
            if (i == end) end = maxi;
        }
        return end >= n - 1;
    }

    bool canJump3(vector<int>& nums) {
        int goal = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (i + nums[i] >= goal)
                goal = i + nums[i];
            if (goal <= i || goal >= nums.size() - 1) break;
        }
        return goal >= nums.size() - 1;
    }
    bool canJump1(vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = goal - 1; i > -1; --i)
            if (i + nums[i] >= goal)
                goal = i;
        return goal == 0;
    }
    bool canJump2(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<bool> visited(nums.size(), false);
        stack<int> s;
        s.push(0);
        while (!s.empty()) {
            int x = s.top(); s.pop();
            if (x == n) return true;
            visited[x] = true;
            //for (int i = min(n - x, nums[x]); i > 0; --i)
            for (int i = 1; i <= nums[x] && x + i <= n; ++i)
                if (!visited[x + i])
                    s.push(x + i);
        }

        return false;
    }
};
