class Solution {
    vector<int> uniq;
    map<int, int> freq;

    int partition(int l, int r, int piv) {
        int pfr = freq[uniq[piv]];
        swap(uniq[piv], uniq[r]);

        int ps = l;
        for (int i = l; i<= r; ++i) {
            if (freq[uniq[i]] < pfr) {
                swap(uniq[ps], uniq[i]);
                ++ps;
            }
        }

        swap(uniq[r], uniq[ps]);
        return ps;
    }

    void quickselect(int l, int r, int k) {
        if (l == r) return;
        int piv = l + rand() % (r - l + 1);
        piv = partition(l, r, piv);
        if (k == piv) return;

        if (k < piv)
            quickselect(l, piv - 1, k);
        else
            quickselect(piv + 1, r, k);
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) return nums;

        for(auto n : nums) ++freq[n];
        int n = freq.size();

        for (auto [v, _] : freq) uniq.push_back(v);
        if (n == k) return uniq;

        quickselect(0, n - 1, n - k);

        vector<int> ans(k);
        copy(uniq.begin() + n - k, uniq.end(), ans.begin());
        return ans;
    }
};


class Solution2 {
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
