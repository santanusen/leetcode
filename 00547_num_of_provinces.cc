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

    bool Union(int x, int y) {
        int px = Find(x);
        int py = Find(y);
        if (px == py) return false;

        if (rank[px] > rank[py]) root[px] = py;
        else if (rank[px] < rank[py]) root[py] = px;
        else {
            root[py] = px;
            ++rank[px];
        }
        return true;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        int prov = n;
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                if (isConnected[i][j] && ds.Union(i, j))
                    --prov;
        return prov;
    }
};
