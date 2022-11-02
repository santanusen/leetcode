class Solution {
    
public:
        
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<tuple<int, int, int, int>> q;
        q.push(make_tuple(0, 0, 0, k));
        
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));
        
        while (!q.empty()) {
            auto t = q.front();
            int x = get<0>(t), y = get<1>(t), mo = get<2>(t), o = get<3>(t);
            q.pop();
            if (x == grid.size() - 1 && y == grid[0].size() - 1)
                return mo;
            
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
                continue;
            
            if (grid[x][y])
                    --o;
            if (o < 0)
                continue;
            
            if (vis[x][y] != -1 && vis[x][y] >= o) // Already visited with more or equal remaining obstacles: can't improve
                continue;
            
            // Visit current.
            vis[x][y] = o;
            
            q.push(make_tuple(x - 1, y, mo + 1, o));
            q.push(make_tuple(x + 1, y, mo + 1, o));
            q.push(make_tuple(x, y - 1, mo + 1, o));
            q.push(make_tuple(x, y + 1, mo + 1, o));
            
        }
        
        return -1;
    }
    
};
