class Solution {
    int ds_find(int i, vector<int>& parent) {
        if (parent[i] != i)
            parent[i] = ds_find(parent[i], parent);
        return parent[i];
    }
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        // Sort edges bsed on greatest node.
        sort(edges.begin(), edges.end(),
            [&](vector<int>& l, vector<int>& r) {
                return max(vals[l[0]], vals[l[1]]) < max(vals[r[0]], vals[r[1]]);
            });
        
        // Count
        vector<int> cnt(vals.size(), 1);
        
        // DS parent
        vector<int> parent(vals.size());
        for (int i = 0; i < vals.size(); ++i)
            parent[i] = i;

        int ans = 0;
        for (auto& e: edges) {
            int a = ds_find(e[0], parent);
            int b = ds_find(e[1], parent);
            if (vals[a] != vals[b]) {
                if (vals[a] > vals[b])
                    parent[b] = a;
                else
                    parent[a] = b;
            } else {
                parent[a] = b;
                ans += (cnt[a] * cnt[b]);
                cnt[b] += cnt[a];
            }
        }

        return ans + vals.size();      
    }
};
