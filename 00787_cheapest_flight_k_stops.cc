class Solution {
    int res;

    void dfs(vector<vector<vector<int>>>& nbrs, vector<bool>& visited, int cur, int dst, int k, int cost) {
        if (k < 0) return;
        if (cur == dst) {
            res = min(res, cost);
        }
        visited[cur] = true;
        for (auto& nbr : nbrs[cur])
            if (!visited[nbr[0]] && cost + nbr[1] < res)
                dfs(nbrs, visited, nbr[0], dst, k - 1, cost + nbr[1]);
        visited[cur] = false;
    }

    void bfs(vector<vector<pair<int, int>>>& nbrs, vector<int>& cost, int src, int k) {
        cost[src] = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;
        while (!q.empty() && stops <= k) {
            int sz = q.size();
            while (sz--) {
                auto [cur, ccost] = q.front(); q.pop();
                for (auto [nbr, price] : nbrs[cur]) {
                    int ncost = ccost + price;
                    if (ncost < cost[nbr]) {
                        cost[nbr] = ncost;
                        q.push({nbr, ncost});
                    }
                }
            }
            ++stops;
        }
    }

public:
    // BFS
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> nbrs(n);
        for (auto& e : flights)
            nbrs[e[0]].push_back({e[1], e[2]});

        vector<int> cost(n, INT_MAX);
        bfs(nbrs, cost, src, k);
        return (cost[dst] == INT_MAX) ? -1 : cost[dst];
    }

    int findCheapestPrice_dfs(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> nbrs(n);
        for (auto& e : flights)
            nbrs[e[0]].push_back({e[1], e[2]});

        res = INT_MAX;
        vector<bool> visited(n, false);
        dfs(nbrs, visited, src, dst, k + 1, 0);
        return res != INT_MAX ? res : -1;
    }

    int findCheapestPrice_bellman_ford(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Bellman-Ford
        vector<vector<int>> c(k + 2, vector<int>(n, 1e8));
        c[0][src] = 0;
        
        for(int z = 1; z <= k + 1; z++){
            //vector<int> C(c);
            c[z][src] = 0;
            for(auto e: flights)
                c[z][e[1]] = min(c[z][e[1]], c[z - 1][e[0]] + e[2]);
            //c.swap(C);
        }
        return c[k + 1][dst] == 1e8 ? -1 : c[k + 1][dst];
    }
};
