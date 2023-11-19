class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1, steps = 0; i < nums.size(); ++i, ans += steps)
            if (nums[i] != nums[i - 1])
                ++steps;

        return ans;
    }

    int reductionOperations1(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto num : nums)
            ++freq[num];

        int n = freq.size();
        pair<int, int> fvec[n];
        int i = 0;
        for (auto [v, f] : freq)
            fvec[i++] = {v, f};

        sort(fvec, fvec + n);
        int ans = 0;
        for (int i = n - 1; i > 0; --i) {
            int f = fvec[i].second;
            ans += f;
            fvec[i - 1].second += f;
        }

        return ans;
    }

    int reductionOperations2(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto num : nums)
            ++freq[num];

        priority_queue<pair<int, int>> pq;
        for (auto [num, f] : freq)
            pq.push({num, f});

        int ans = 0;
        while (pq.size() > 1) {
            auto [n1, f1] = pq.top(); pq.pop();
            auto [n2, f2] = pq.top(); pq.pop();
            pq.push({n2, f2 + f1});
            ans += f1;
        }

        return ans;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
