class Solution {
public:
    std::vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {      
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        int m = (n - 1) / 8 + 1;

        std::vector<uint8_t> has_inflows(m, 0); // tracks nodes with zero degree-in  
        for(const auto& edge: edges) {
            int group = edge[1] / 8;
            int idx = edge[1] % 8;
            has_inflows[group] |= (1 << idx);
        }
        std::vector<int> set_of_nodes;          // find the vertices that have no inflows
        for(int i = 0; i < n; ++i) {
            int group = i / 8;
            int idx = i % 8;
            if((has_inflows[group] & (1 << idx)) == 0)
                set_of_nodes.push_back(i);
        }
        return set_of_nodes;
    }

    vector<int> findSmallestSetOfVertices2(int n, vector<vector<int>>& edges) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        vector<bool> has_indeg(n, false);
        for (auto& e : edges)
            has_indeg[e[1]] = true;

        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (!has_indeg[i])
                ans.push_back(i);

        return ans;
    }
};
