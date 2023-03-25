class DisjointSet {
    vector<int> root;
    vector<int> rank;

public:

    DisjointSet(int n) : root(n), rank(n, 0) {
        for (int i = 0; i < n; ++i)
            root[i] = i;
    }

    int Find(int x) {
        if (root[x] != x)
            root[x] = Find(root[x]);
        return root[x];
    }

    bool Union(int x, int y) {
        int px = Find(x), py = Find(y);
        if (px == py) return false;
        int rpx = rank[px], rpy = rank[py];
        if (rpx > rpy) root[py] = px;
        else if (rpy < rpx) root[px] = py;
        else {
            root[py] = px;
            ++rank[px];
        }
        return true;
    }

};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for (auto& e : edges)
            ds.Union(e[0], e[1]);

        unordered_map<int, long long> islands;
        for (int i = 0; i < n; ++i)
            ++islands[ds.Find(i)];
        
        /*
        long long res = 0, sum = 0;
        for (auto& [_, freq] : islands) {
            res += (freq * sum);
            sum += freq;
        }

        return res;
        */

        long long res = 0;
        for (auto& [_, freq] : islands)
            res += (freq * (n - freq));

        return res >> 1;
    }
};

class Solution_dfs {
    int dfs(int cur, vector<vector<int>>& adj, vector<bool>& visited) {
        int count = 1;
        visited[cur] = true;
        for (auto nbr : adj[cur])
            if (!visited[nbr])
                count += dfs(nbr, adj, visited);
        return count;
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        long long npairs = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            long long csize = dfs(i, adj, visited);
            npairs += csize * (n - csize);
        }

        return npairs >> 1;
    }
};

class Solution_bfs {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        long long npairs = 0;
        queue<int> q;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            long long csize = 0;

            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                ++csize;
                auto cur = q.front(); q.pop();
                for (auto nbr : adj[cur])
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
            }
            npairs += csize * (n - csize);
        }

        return npairs >> 1;
    }
};
