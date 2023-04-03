class Solution { // Kahn's Algorithm
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<int> indeg(n, 0);
        for (auto e : edges)
            if (e != -1)
                ++indeg[e];
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indeg[i] == 0)
                q.push(i);
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            visited[cur] = true;
            auto nbr = edges[cur];
            if (nbr != -1 && --indeg[nbr] == 0)
                q.push(nbr);
        }

        int cyclmax = -1;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            visited[i] = true;

            int len = 1;
            for (int nbr = edges[i]; nbr != i; nbr = edges[nbr]) {
                visited[nbr] = true;
                ++len;
            }

            cyclmax = max(cyclmax, len);
        }

        return cyclmax;
    }
};

class Solution_dfs {
    int cyclmax;
    void dfs(int cur, int id, int seq, vector<int>& edges, vector<int>& vseq, vector<int>& vid) {
        vseq[cur] = seq;
        vid[cur] = id;

        int nbr = edges[cur];
        if (nbr == -1) return;

        if (vseq[nbr] == 0)
            dfs(nbr, id, seq + 1, edges, vseq, vid);
        else
            if (vid[nbr] == id)
                cyclmax = max(cyclmax, seq + 1 - vseq[nbr]);
    }

public:
    int longestCycle(vector<int>& edges) {
        cyclmax = -1;
        int n = edges.size();
        vector<int> vseq(n, 0);
        vector<int> vid(n);

        for (int i = 0; i < n; ++i)
            if (vseq[i] == 0)
                dfs(i, i, 1, edges, vseq, vid);

        return cyclmax;
    }
};
