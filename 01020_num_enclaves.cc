class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 0) return;

        // Mark current land as visited
        grid[i][j] = 0;

        // Recursively explore 4 directions
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

public:

    int numEnclaves(vector<vector<int>>& grid) {
        for (int c = 0; c < grid[0].size(); ++c) {
            dfs(grid, 0, c);
            dfs(grid, grid.size() - 1, c);
        }
        for (int r = 1; r < grid.size() - 1; ++r) {
            dfs(grid, r, 0);
            dfs(grid, r, grid[0].size() - 1);
        }

        int ans = 0;
        for(int i = 1; i < grid.size() - 1; i++)
            for(int j = 1; j < grid[i].size() - 1; j++)
                ans += grid[i][j];

        return ans;
    }
};



class Solution_DFS {
private:
    pair<bool, int> dfs(vector<vector<int>>& grid, int i, int j) {
        // Out of bounds are not considered as moves
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size()) return {false, 0};
        
        // Return 0 if it's sea or a visited cell
        if (grid[i][j] == 0 || grid[i][j] == 2) return {true, 0};

        // Mark current land as visited
        grid[i][j] = 2;

        // Recursively explore 4 directions
        auto [isTopValid, topMoves] = dfs(grid, i - 1, j);
        auto [isBottomValid, bottomMoves] = dfs(grid, i + 1, j);
        auto [isLeftValid, leftMoves] = dfs(grid, i, j - 1);
        auto [isRightValid, rightMoves]= dfs(grid, i, j + 1);

        // If it's valid, return number of moves found
        if(isTopValid && isBottomValid && isLeftValid && isRightValid) {
            return {true, 1 + (leftMoves + rightMoves + topMoves + bottomMoves)};
        }

        return {false, 0};
    }

public:
    // T:O(mn), S:O(mn)
    int numEnclaves(vector<vector<int>>& grid) {
        int moves = 0;

        // Go through all cells in a grid
        for(int i = 0; i < grid.size(); i++) { // O(n)
            for(int j = 0; j < grid[i].size(); j++) { // O(m)
                if(grid[i][j] == 1) {
                    auto [isValid, numMoves] = dfs(grid, i, j);

                    // Increment moves if it's valid
                    if(isValid) moves += numMoves;
                }
            }
        }
        return moves;
    }
};


class Solution_BFS {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 1; i < m - 1; ++i)
            for (int j = 1; j < n - 1; ++j)
                if (grid[i][j] == 1) {
                    int l = 0;
                    bool encl = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        if (x < 0 || x >= m || y < 0 || y >= n)
                            encl = false;
                        else if (grid[x][y] == 1) {
                            ++l;
                            grid[x][y] = 0; // Visited
                            for (int d = 0; d < 4; ++d)
                                q.push({x + dx[d], y + dy[d]});
                        }
                    }
                    if (encl) ans += l;
                }

        return ans;
        
    }
};
