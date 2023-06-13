static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited) {
        int n = isConnected.size();
        visited[i] = true;

        for(int j = 0; j < n; ++j)
            if (isConnected[i][j] == 1 && visited[j] == false)
                dfs(isConnected, j, visited);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n);
        int prov = 0;
        for (int i = 0; i < n; ++i) {
            
            if (visited[i] == false) {
                isConnected[i][i] = 0;
                ++prov;
                dfs(isConnected, i, visited);
            }
        }
        return prov;
    }
};

/*
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


class Solution2 {
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
*/
