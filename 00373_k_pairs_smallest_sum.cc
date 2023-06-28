class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> ans;
        set<pair<int, int>> visited;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> minHeap;
        minHeap.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0, 0});

        while (k-- && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
                minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return ans;
    }
    
    vector<vector<int>> kSmallestPairs2(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int>> pq;
        int n = nums1.size(), m = nums2.size();

        for (auto a : nums1) {
            for (auto b : nums2) {
                int s = a + b;
                if (pq.size() < k)
                    pq.push({s, a, b});
                else if (get<0>(pq.top()) > s) {
                    pq.pop();
                    pq.push({s, a, b});
                }
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto [_, a, b] = pq.top();
            ans.push_back({a, b});
            pq.pop();
        }

        return ans;
        
    }
};
