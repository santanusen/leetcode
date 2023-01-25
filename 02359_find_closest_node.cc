class Solution {
    void bfs(vector<int>& edges, int node, vector<int>& dist) {
        queue<int> q;
        dist[node] = 0;
        q.push(node);
        while (!q.empty()) {
            node = q.front(); q.pop();
            int nbr = edges[node];
            if (nbr != -1 && dist[nbr] == INT_MAX) {
                dist[nbr] = dist[node] + 1;
                q.push(nbr);
            }
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> d1(edges.size(), INT_MAX), d2(edges.size(), INT_MAX);
        for (int i = node1, d = 0; i != -1 && d1[i] == INT_MAX; i = edges[i])
            d1[i] = d++;

        int res = INT_MAX, mdist = INT_MAX;
        for (int i = node2, d = 0; i != -1 && d2[i] == INT_MAX; i = edges[i]) {
            d2[i] = d++;
            int md = max(d1[i], d2[i]);
            if (md <= mdist) {
                res = (md < mdist) ? i : min(res, i);
                mdist = md;
            }
        }

        return (mdist == INT_MAX) ? -1 : res;
    }

    int closestMeetingNode_BFS(vector<int>& edges, int node1, int node2) {
        vector<int> d1(edges.size(), INT_MAX), d2(edges.size(), INT_MAX);
        bfs(edges, node1, d1);
        bfs(edges, node2, d2);

        int mnode = 0, mdist = max(d1[0], d2[0]);
        for (int i = 1, d; i < d1.size(); ++i) {
            if ((d = max(d1[i], d2[i])) < mdist) {
                mdist = d;
                mnode = i;
            }
        }

        return ((mdist != INT_MAX) ? mnode : -1);
    }
};
