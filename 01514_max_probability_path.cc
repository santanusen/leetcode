auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return false;
    }();
    
class Solution { // Dijkstra's
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> max_prob(n, 0.0);
        max_prob[start] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});

        vector<bool> visited(n, false);

        while (!pq.empty()) {
            auto [_, cur] = pq.top(); pq.pop();
            if (visited[cur]) continue;
            visited[cur] = true;
            double cprob = max_prob[cur];
            for (auto [nbr, nprob] : adj[cur]) {
                auto prob = cprob * nprob;
                if (prob > max_prob[nbr]) {
                    max_prob[nbr] = prob;
                    visited[nbr] = false; // Priority increased.
                    pq.push({max_prob[nbr], nbr});
                }
            }
        }

        return max_prob[end];

    }
};

class Solution_SPFA {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> max_prob(n, 0.0);
        max_prob[start] = 1.0;

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            double cprob = max_prob[cur];
            for (auto [nbr, nprob] : adj[cur]) {
                auto prob = cprob * nprob;
                if (prob > max_prob[nbr]) {
                    max_prob[nbr] = prob;
                    q.push(nbr);
                }
            }
        }

        return max_prob[end];

    }
};


class Solution_Bellman_Ford {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> max_prob(n, 0.0);
        max_prob[start] = 1.0;

        bool relaxed = true;
        auto relax = [&](int s, int d, double p) -> bool {
            double prob = max_prob[s] * p;
            if (prob > max_prob[d]) {
                max_prob[d] = prob;
                return true;
            }
            return false;
        };

        for (int i = 0; (i < n - 1) && (relaxed == true); ++i) {
            relaxed = false;
            for (int j = 0; j < edges.size(); ++j) {
                /*double prob = max_prob[edges[j][0]] * succProb[j];
                if (prob > max_prob[edges[j][1]]) {
                    max_prob[edges[j][1]] = prob;
                    relaxed = true;
                }

                prob = max_prob[edges[j][1]] * succProb[j];
                if (prob > max_prob[edges[j][0]]) {
                    max_prob[edges[j][0]] = prob;
                    relaxed = true;
                }*/
                if (relax(edges[j][0], edges[j][1], succProb[j])) relaxed = true;
                if (relax(edges[j][1], edges[j][0], succProb[j])) relaxed = true;
            }
        }

        return max_prob[end];
    }
};

class Solution_DFS {
    double dfs(vector<vector<pair<int, double>>>& adj, int cur, int end, double prob, vector<bool>& visited) {
        if (cur == end || prob == 0.0) {
            return prob;
        }

        visited[cur] = true;

        double pmax = 0.0;
        for (auto [nbr, nprob] : adj[cur]) {
            if (!visited[nbr]) {
                pmax = max(pmax, dfs(adj, nbr, end, prob * nprob, visited));
            }
        }

        visited[cur] = false;

        return pmax;

    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<bool> visited(n, false);
        return dfs(adj, start, end, 1.0, visited);
    }
};
