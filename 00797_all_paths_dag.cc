class Solution {
    void DFS (vector<vector<int>>& g, int cur, vector<bool>& visited,
              vector<vector<int>>& res, vector<int>& path) {
                  visited[cur] = true;
                  path.push_back(cur);

                  if (cur + 1 == g.size())
                      res.push_back(path);
                  else
                      for (auto n : g[cur])
                        if (!visited[n])
                            DFS(g, n, visited, res, path);

                  path.pop_back();
                  visited[cur] = false;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> visited(graph.size(), false);
        DFS(graph, 0, visited, res, path);
        return res;
    }
}
