class Solution {
public:
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        if (k == nums.size()) return nums;

        unordered_map<int, int> freq;
        for (auto n : nums) ++freq[n];
        if (freq.size() == k) {
            vector<int> ans(k);
            transform(freq.begin(), freq.end(), ans.begin(), [](auto& p){return p.first;});
            return ans;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& nf : freq) {
            pq.push({nf.second, nf.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (pq.size()) { // for (int i = 0; i < k; ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto n : nums) ++freq[n];
        vector<pair<int, int>> fv;
        for (auto& [n, f] : freq) fv.push_back({f, n});
        sort(fv.begin(), fv.end(), greater<pair<int, int>>());
        vector<int> ans(k);
        //for (int i = 0; i < k; ++i) ans[i] = fv[i].second;
        transform(fv.begin(), fv.begin() + k, ans.begin(), [](auto& p){return p.second;});
        return ans;
    }
};
