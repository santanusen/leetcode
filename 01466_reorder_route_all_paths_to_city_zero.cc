class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Create Adjacency Lists of predecessors and successors.
        vector<vector<int>> pred(n), succ(n);
        for (auto& e : connections) {
            pred[e[1]].push_back(e[0]);
            succ[e[0]].push_back(e[1]);
        }

        // Start BFS from Node 0.
        // For each node, add the predecessors in the BFS queue.
        // If the node has some successors which are not yet visited,
        // add them to the BFS queue as well and increment the correction
        // count for each such successor.
        int corrections = 0;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            auto cur = q.front(); q.pop();

            for (auto p : pred[cur])
                if (!visited[p]) {
                    visited[p] = true;
                    q.push(p);
                }

            for (auto s : succ[cur])
                if (!visited[s]) {
                    ++corrections;
                    visited[s] = true;
                    q.push(s);
                }
        }

        return corrections;
        
    }
};
