class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if (roads.size() < 2) return roads.size();

        vector<int> deg(n, 0);
        //int deg[100] = {0};
        vector<vector<bool>> conn(n, vector<bool>(n, false));

        for (auto& e : roads) {
            int i = e[0], j = e[1];
            ++deg[i];
            ++deg[j];
            conn[i][j] = conn[j][i] = true;
        }

        int ans = 0;

        for (int i = 0; i + 1 < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                int v = deg[i] + deg[j];
                if (conn[i][j])
                    --v;
                ans = max(ans, v);
            }

        return ans;
        
    }

    int maximalNetworkRank_sort(int n, vector<vector<int>>& roads) {
        if (roads.size() < 2) return roads.size();

        vector<unordered_set<int>> g(n);

        for (auto& e : roads) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }

        vector<pair<int, int>> r;
        for (int i = 0; i < n; ++i)
            if (!g[i].empty())
                r.push_back({g[i].size(), i});

        sort(r.begin(), r.end(), greater<pair<int, int>>());
        int ans = r[0].first + r[1].first;
        if (g[r[0].second].find(r[1].second) != g[r[0].second].end())
            --ans;
        else
            return ans;

        for (int i = 0; i + 1 < r.size() && r[0].first == r[i].first; ++i)
            for (int j = i + 1; j < r.size() && r[1].first == r[j].first; ++j) {
                int v = r[i].first + r[j].first;
                if (g[r[i].second].find(r[j].second) != g[r[i].second].end())
                    --v;
                ans = max(ans, v);
            }

        return ans;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
