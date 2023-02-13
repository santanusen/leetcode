class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> rnbrs(n), bnbrs(n);
        for (auto& e : redEdges)
            rnbrs[e[0]].push_back(e[1]);

        for (auto& e : blueEdges)
            bnbrs[e[0]].push_back(e[1]);

        vector<bool> rvisited(n, false), bvisited(n, false);
        vector<int> dist(n, -1);
        dist[0] = 0;

        enum color {R, B};
        queue<pair<int, color>> q;
        q.push({0, R});
        q.push({0, B});
        int d = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                auto p = q.front(); q.pop();
                if (p.second == R)
                    rvisited[p.first] = true;
                else
                    bvisited[p.first] = true;
                if (dist[p.first] == -1 || dist[p.first] > d)
                    dist[p.first] = d;

                color c = (p.second == R) ? B : R;
                auto& nbrs = (c == B) ? bnbrs[p.first] : rnbrs[p.first];
                auto& visited = (c == B) ? bvisited : rvisited;
                for (auto nbr : nbrs)
                    if (!visited[nbr])
                        q.push({nbr, c});
            }
            ++d;
        }

        return dist;
        
    }
};
