class Solution {
    bool dfs(int src, int dst, unordered_map<int, unordered_set<int>>& nbrs, unordered_set<int>& visited) {
        if (src == dst) return true;
        visited.insert(src);
        if (!nbrs.count(src)) return false;

        for (auto nbr : nbrs[src]) {
            if (!visited.count(nbr)) {
                if (dfs(nbr, dst, nbrs, visited))
                    return true;
            }
        }

        return false;
    }

int findParent(int x, vector<int>& par) {
    if (par[x] != x)
        par[x] = findParent(par[x], par);
    return par[x];
}

void djsUnion(int a, int b, vector<int>& par) {
    int pa = findParent(a, par);
    int pb = findParent(b, par);
    if (pa != pb)
        par[pb] = pa;
}

public:
    bool validPath_dfs(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, unordered_set<int>> nbrs;
        for (auto &e : edges) {
            nbrs[e[0]].insert(e[1]);
            nbrs[e[1]].insert(e[0]);
        }
        unordered_set<int> visited;
        return dfs(source, destination, nbrs, visited);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> par(n);
        for (int i = 0; i < n; ++i) par[i] = i;
        for (auto& e : edges) djsUnion(e[0], e[1], par);
        return findParent(source, par) == findParent(destination, par);
    }
};


