class Solution {
    long long fuel;
    long long dfs(int cur, int par, vector<vector<int>>& nbrs, int seats) {
        long long nodes = 1;
        for (auto nbr : nbrs[cur])
            if (nbr != par)
                nodes += dfs(nbr, cur, nbrs, seats);
        if (cur != 0) {
            fuel += (nodes / seats);
            if (nodes % seats) ++fuel;
        }

        return nodes;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {

        vector<vector<int>> nbrs(roads.size() + 1);
        for (auto& r : roads) {
            nbrs[r[0]].push_back(r[1]);
            nbrs[r[1]].push_back(r[0]);
        }
        fuel = 0;
        dfs(0, -1, nbrs, seats);
        return fuel;
        
    }
};
