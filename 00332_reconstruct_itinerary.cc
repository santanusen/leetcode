class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj; 
    vector<string> ans;

    void dfs(string cur) {
        auto& pq = adj[cur];
        while (!pq.empty()) {
            string nbr = pq.top(); pq.pop();
            dfs(nbr);
        }

        ans.push_back(cur);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& t : tickets)
            adj[t[0]].push(t[1]);

        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }

};


class Solution2 {
    bool dfs(unordered_map<string, map<string, int>>& adj, const string& cur, int n, vector<string>& ans) {
        if (ans.size() == n)
            return true;

        auto& nbrs = adj[cur];
        if (nbrs.empty())
            return false;

        for (auto& nent: nbrs) {
            if (nent.second == 0) continue;
            ans.push_back(nent.first);
            --(nent.second);
            if (dfs(adj, nent.first, n, ans))
                return true;
            ++(nent.second);
            ans.pop_back();
        }

        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> adj;
        for (auto& t : tickets)
            ++(adj[t[0]][t[1]]);

        vector<string> ans{"JFK"};
        dfs(adj, "JFK", tickets.size() + 1, ans);

        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
