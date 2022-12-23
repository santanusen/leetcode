class Solution {
    vector<unordered_set<int>> nbrs;
    vector<int> res;
    vector<int> count;

    void dfs(int cur, int par) {
        for (auto chd : nbrs[cur]) {
            if (chd != par) {
                dfs(chd, cur);
                count[cur] += count[chd];
                res[cur] += (count[chd] + res[chd]);
            }
        }
    }

    void dfs2(int cur, int par) {
        for (auto chd : nbrs[cur]) {
            if (chd != par) {
                res[chd] = res[cur] - count[chd] + res.size() - count[chd];
                dfs2(chd, cur);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        nbrs.resize(n);
        for (auto& e : edges) {
            nbrs[e[0]].insert(e[1]);
            nbrs[e[1]].insert(e[0]);
        }

        res.assign(n, 0);
        count.assign(n, 1);

        dfs(0, -1);
        dfs2(0, -1);

        return res;
    }

    vector<int> sumOfDistancesInTree3(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> nbrs(n);
        for (auto& e : edges) {
            nbrs[e[0]].insert(e[1]);
            nbrs[e[1]].insert(e[0]);
        }

        vector<int> res(n);
        // BFS for each node
        for (int i = 0; i < n; ++i) {
            res[i] = 0;
            int d = 0;
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int sz = q.size();
                for (int j = 0; j < sz; ++j) {
                    int x = q.front(); q.pop();
                    if (visited[x]) continue;
                    visited[x] = true;
                    res[i] += d;
                    for (auto n : nbrs[x])
                        q.push(n);
                }
                ++d;
            }
        }

        return res;
    }


    vector<int> sumOfDistancesInTree2(int n, vector<vector<int>>& edges) {
        const int DMAX = n + 1;
        vector<vector<int>> d (n, vector<int>(n, DMAX));
        for (auto& e : edges)
            d[e[0]][e[1]] = d[e[1]][e[0]] = 1;
        for (int i = 0; i < n; ++i)
            d[i][i] = 0;

        bool refined;

        do {
            refined = false;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    for (int k = 0; k < n; ++k)
                        if (d[i][k] + d[k][j] < d[i][j]) {
                            d[i][j] = d[i][k] + d[k][j];
                            refined = true;
                        }
        } while (refined);
        
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                res[i] += d[i][j];

        return res;
    }


};
