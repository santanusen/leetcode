class Solution {
public:
    
    unordered_map<int, int> f;
    int islands;
    
    int find(int x) {
        if (!f.count(x)) {
            f[x] = x;
            ++islands;
        }
        
        if (f[x] != x)
            f[x] = find(f[x]);
        
        return f[x];
    }
    
    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x != y) {
            f[x] = y;
            --islands;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        islands = 0;
        for (auto& s : stones)
            uni(s[0], ~s[1]);
        return stones.size() - islands;
    }
    
    int removeStones2(vector<vector<int>>& stones) {
        vector<int> color(stones.size(), 0);
        int c = 0;
        
        for (int i = 0; i < stones.size(); ++i) {
            if (color[i])
                continue;
            ++c;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int k = q.front(); q.pop();
                color[k] = c;
                for (int j = 0; j < stones.size(); ++j)
                    if (!color[j] && (stones[k][0] == stones[j][0] ||
                        stones[k][1] == stones[j][1]))
                        q.push(j);
            }
        }
        
        return stones.size() - c;
    }
    
    /*
    int removeStonesFailed(vector<vector<int>>& stones) {
        unordered_map<int, unordered_set<int>> adj;
        
        for (int i = 0; i + 1 < stones.size(); ++i)
            for (int j = i + 1; j < stones.size(); ++j)
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    adj[i].insert(j);
                    adj[j].insert(i);
                }
        
        int n = 0;
        
        while (!adj.empty()) {
            int minn = INT_MAX, p = -1;
            for (auto& a : adj) {
                if (a.second.size() < minn) {
                    minn = a.second.size();
                    p = a.first;
                }
            }
            
            for (auto i : adj[p]) {
                adj[i].erase(p);
                if (adj[i].empty())
                    adj.erase(i);
            }
            
            adj.erase(p);
            ++n;
        }
        
        return n;
    }
    */
};
