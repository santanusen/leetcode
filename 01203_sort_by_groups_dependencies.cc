class Solution {
    bool topoSort(vector<unordered_set<int>>& g, vector<int>& indeg, vector<int>& res) {
        stack<int> stk;
        for (int i = 0; i < indeg.size(); ++i)
            if (!indeg[i])
                stk.push(i);

        while (!stk.empty()) {
            auto cur = stk.top(); stk.pop();
            res.push_back(cur);

            for (auto nbr : g[cur])
                if (--indeg[nbr] == 0)
                    stk.push(nbr);
        }

        return res.size() == g.size();
    }

public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Assign unique groups
        for (int i = 0; i < n; ++i)
            if (group[i] == -1)
                group[i] = m++;

        vector<unordered_set<int>> igraph(n), ggraph(m);
        vector<int> iindeg(n), gindeg(m);

        // Build dep graph
        for (int cur = 0; cur < n; ++cur)
            for (int prv : beforeItems[cur]) {
                // prv -> cur
                igraph[prv].insert(cur);
                ++iindeg[cur];

                if (group[cur] != group[prv]) {
                    if (ggraph[group[prv]].insert(group[cur]).second)
                        ++gindeg[group[cur]];
                }
            }

        // Topo sort
        vector<int> iorder, gorder;
        if (!topoSort(igraph, iindeg, iorder))
            return {};

        if (!topoSort(ggraph, gindeg, gorder))
            return {};

        // Arrange sorted items by groups
        vector<vector<int>> sg(m);
        for (auto item : iorder)
            sg[group[item]].push_back(item);

        // Arrange grouped items in group order
        vector<int> ans;
        for (auto gidx : gorder)
            ans.insert(ans.end(), sg[gidx].begin(), sg[gidx].end());

        return ans;

    }
};
