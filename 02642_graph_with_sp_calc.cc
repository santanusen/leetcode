class Graph {
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int n, vector<vector<int>>& edges) :
        adj(n) {
            for (auto& edge : edges)
                addEdge(edge);
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[2], edge[1]});
    }
    
    int shortestPath(int node1, int node2) {
        if (node1 == node2) return 0;

        vector<bool> visited(adj.size(), false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, node1});

        while (!pq.empty()) {
            auto [cst, node] = pq.top();
            pq.pop();

            if (node == node2)
                return cst;

            if (visited[node])
                continue;

            visited[node] = true;

            for (auto [ecst, nbr] : adj[node]) {
                if (!visited[nbr])
                    pq.push({cst + ecst, nbr});
            }
        }

        return -1;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
