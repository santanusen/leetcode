static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class UnionFind {
    vector<int> group;

public:
    UnionFind(int n) {
        for (int i = 0; i < n; ++i)
            group.push_back(i);
    }

    int FindGroup(int x) {
        if (group[x] != x)
            group[x] = FindGroup(group[x]);
        return group[x];
    }

    void Join(int x, int y) {
        int gx = FindGroup(x), gy = FindGroup(y);
        if (gx != gy)
            group[gy] = gx;
    }

    bool Connected(int x, int y) {
        return FindGroup(x) == FindGroup(y);
    }

};

class Solution {
    bool dfs(vector<vector<int>>& graph, int cur, vector<uint8_t>& color) {
        uint8_t ncol = color[cur] % 2 + 1;
        for (auto nbr : graph[cur]) {
            if (!color[nbr]) {
                color[nbr] = ncol;
                if (!dfs(graph, nbr, color))
                    return false;
            } else if (color[nbr] != ncol)
                return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        UnionFind uf(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                if (uf.Connected(i, graph[i][j]))
                    return false;
                uf.Join(graph[i][0], graph[i][j]);
            }
        }

        return true;
    }

    bool isBipartite_dfs(vector<vector<int>>& graph) {
        vector<uint8_t> color(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i) {
            if (!color[i]) {
                color[i] = 1;
                if (!dfs(graph, i, color))
                    return false;
            }
        }
        return true;
    }

    bool isBipartite_bfs(vector<vector<int>>& graph) {
        vector<int8_t> color(graph.size(), -1);

        queue<int> q;
        for (int i = 0; i < graph.size(); ++i) {
            if (color[i] != -1) continue;

            color[i] = 1;
            q.push(i);
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                int8_t ncol = color[cur] ^ 1;
                for (auto nbr : graph[cur]) {
                    if (color[nbr] == -1) {
                        color[nbr] = ncol;
                        q.push(nbr);
                    } else if (color[nbr] != ncol)
                        return false;
                }
            }
        }
        return true;
        
    }
};
