class Solution {
    bool intersect(vector<int>& r1, vector<int>& r2) {
        for (int i = 0, j = 0; i < r1.size() && j < r2.size(); ) {
            if (r1[i] == r2[j])
                return true;
            (r1[i] < r2[j]) ? ++i : ++j;
        }
        return false;
    }

public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        vector<bool> dest(routes.size());
        queue<int> q;
        vector<vector<int>> adj(routes.size());
        vector<bool> visited(routes.size());

        for (int i = 0; i < routes.size(); ++i) {
            auto& route = routes[i];
            sort(route.begin(), route.end());
            if (binary_search(route.begin(), route.end(), source)) {
                q.push(i);
                visited[i] = true;
            }
            if (binary_search(route.begin(), route.end(), target))
                dest[i] = true;

            for (int j = 0; j < i; ++j) {
                /*
                vector<int> isec;
                set_intersection(route.begin(), route.end(),
                                 routes[j].begin(), routes[j].end(),
                                 back_inserter(isec));
                */
                if (intersect(route, routes[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 1;
        while (!q.empty()) {
            int l = q.size();
            while (l--) {
                int cur = q.front(); q.pop();
                if (dest[cur])
                    return ans;
                visited[cur] = true;
                for (auto nbr : adj[cur])
                    if (!visited[nbr])
                        q.push(nbr);
            }
            ++ans;
        }

        return -1;
    }
};

class Solution2 {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, unordered_set<int>> adj;
        for (auto& route : routes) {
            for (auto stn : route)
                adj[stn].insert(route.begin(), route.end());
        }

        int ans = 0;
        queue<int> q;
        unordered_set<int> visited;

        q.push(source);
        visited.insert(source);

        while (!q.empty()) {
            int l = q.size();
            while (l--) {
                auto cur = q.front(); q.pop();
                if (cur == target)
                    return ans;
                visited.insert(cur);
                for (auto nbr : adj[cur])
                    if (visited.find(nbr) == visited.end())
                        q.push(nbr);
            }
            ++ans;
        }


        return -1;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
