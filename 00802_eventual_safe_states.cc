class Solution {
    bool dfs(int i, vector<vector<int>>& g, vector<bool>& visited, vector<bool>& instk) {
        if (instk[i]) return true; // Cycle
        if (visited[i]) return false;

        instk[i] = true;
        visited[i] = true;

        for (auto nbr : g[i])
            if (dfs(nbr, g, visited, instk))
                return true;

        instk[i] = false;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n), instk(n);

        for (int i = 0; i < n; ++i)
            dfs(i, graph, visited, instk);

        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (!instk[i])
                ans.push_back(i);

        return ans;
    }
};

class Solution_Kahns { // Kahn's
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<vector<int>> rg(n);
        vector<int> ideg(n, 0);
        queue<int> q;
        
        for (int i = 0; i < n; ++i) {
            if (graph[i].empty())
                q.push(i);
            else
                for (auto j : graph[i]) {
                    rg[j].push_back(i);
                    ++ideg[i];
                }
        }

        vector<bool> safe(n, false);
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            safe[cur] = true;
            for (auto nbr : rg[cur]) {
                if (--ideg[nbr] == 0)
                    q.push(nbr);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (safe[i])
                ans.push_back(i);

        return ans;
    }
};

class Solution_DFS {
    void dfs(vector<vector<int>>& graph, int cur, vector<int>& visited, unordered_set<int>& path) {
        path.insert(cur);
        visited[cur] = 1;

        for (auto nbr : graph[cur]) {
            if (!visited[nbr])
                dfs(graph, nbr, visited, path);
            else if (visited[nbr] == 2 || path.find(nbr) != path.end()) {
                for (auto i : path)
                    visited[i] = 2;
            }
        }


        path.erase(cur);

    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                unordered_set<int> path;
                dfs(graph, i, visited, path);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (visited[i] == 1)
                ans.push_back(i);

        return ans;
        
    }
};

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return false;}();
