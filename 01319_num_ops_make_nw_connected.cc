class DisjointSet {
    vector<int> root;
    vector<int> rank;

public:
    DisjointSet(int n) : root(n), rank(n, 0) {
        for (int i = 0; i < n; ++i)
            root[i] = i;
    }

    int Find(int x) {
        if (x != root[x])
            root[x] = Find(root[x]);
        return root[x];
    }

    void Union(int x, int y) {
        int px = Find(x);
        int py = Find(y);
        if (px == py) return;

        if (rank[px] > rank[py]) root[px] = py;
        else if (rank[px] < rank[py]) root[py] = px;
        else {
            root[py] = px;
            ++rank[px];
        }
    }
};

class Solution2 {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        DisjointSet ds(n);
        for(auto& c : connections)
            ds.Union(c[0], c[1]);

        unordered_set<int> islands;
        for (int i = 0; i < n; ++i)
            islands.insert(ds.Find(i));

        return islands.size() - 1;
    }
};

class Solution {
    int findParent(int x, vector<int>& par) {
        if (par[x] != x)
            par[x] = findParent(par[x], par);
        return par[x];
    }

    bool djsUnion(int a, int b, vector<int>& par) {
        int pa = findParent(a, par);
        int pb = findParent(b, par);
        if (pa != pb) {
            par[pb] = pa;
            return true;
        }
        return false;
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<int> par(n);
        for (int i = 0; i < n; ++i) par[i] = i;

        int ans = n;
        for(auto& c : connections)
            if (djsUnion(c[0], c[1], par))
                --ans;

        /*unordered_set<int> djs;
        for (int i = 0; i < n; ++i)
            djs.insert(findParent(i, par));

        return djs.size() - 1;
        */
        return ans - 1;
        
    }
};
