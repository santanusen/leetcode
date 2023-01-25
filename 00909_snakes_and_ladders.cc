class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int n = board.size();
        const int ncell = n * n;
        vector<int> dist(ncell + 1, -1);
        dist[1] = 0;
        
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (int next = curr + 1; next <= min(curr + 6, ncell); next++) {
                // Top row has the highest labels, bottom the lowest.    
                int row = (n - 1) - (next - 1) / n;
                // Adjust column direction based on whether row is odd or even.
                int column = (next - 1) % n;
                if (!((n - row) & 1)) column = (n - 1) - column;

                int dest = (board[row][column] != -1) ? board[row][column] : next;
                if (dist[dest] == -1) {
                    dist[dest] = dist[curr] + 1;
                    if (dest == ncell) // All done.
                        break;
                    q.push(dest);
                }
            }
        }

        return dist[ncell];
    }
};
