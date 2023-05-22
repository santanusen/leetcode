class Solution {
    double dfs(unordered_map<string, vector<pair<string, double>>>& nbrs,
               const string& cur, const string& dst, unordered_set<string>& visited) {
 
        if (cur == dst) return 1.0;
        visited.insert(cur);

        double ans = -1.0;
        for (auto& n : nbrs[cur]) {
            if (visited.find(n.first) != visited.end())
                continue;
            double val = dfs(nbrs, n.first, dst, visited);
            if (val >= 0) {
                ans = val * n.second;
                break;
            }
        }

        visited.erase(cur);
        return ans;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> nbrs;

        for (int i = 0; i < values.size(); ++i) {
            nbrs[equations[i][0]].push_back({equations[i][1], values[i]});
            nbrs[equations[i][1]].push_back({equations[i][0], (1.00 / values[i])});
        }

        vector<double> ans;
        unordered_set<string> visited;

        for (auto& q : queries) {
            if (nbrs.find(q[0]) == nbrs.end() || nbrs.find(q[1]) == nbrs.end())
                ans.push_back(-1.0);
            else
                ans.push_back(dfs(nbrs, q[0], q[1], visited));
        }

        return ans;
        
    }
};
