class Solution {
    unsigned matrix_bitmap(vector<vector<int>>& mat) {
        unsigned mb = 0;
        for (int i = 0; i < mat.size(); ++i)
            for (int j = 0; j < mat[0].size(); ++j)
                if (mat[i][j])
                    mb |= (1 << (i * mat[0].size() + j));

        return mb;
    }

    unsigned flip(unsigned mb, int M, int N, int i, int j) {
        int di[] = {0, -1, 1, 0,  0};
        int dj[] = {0,  0, 0, 1, -1};
        for (int k = 0; k < 5; ++k) {
            int ii = i + di[k], jj = j + dj[k];
            if (ii > -1 && ii < M && jj > -1 && jj < N) {
                unsigned mask = (1 << (ii * N + jj));
                if (mb & mask)
                    mb &= ~mask;
                else
                    mb |= mask;  
            }
        }
        return mb;
    }

public:
    int minFlips(vector<vector<int>>& mat) {
        // BFS
        unsigned mb = matrix_bitmap(mat);

        int l = 0;
        unordered_set<unsigned> visited;
        queue<unsigned> q;

        q.push(mb);
        visited.insert(mb);
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                unsigned cur = q.front(); q.pop();
                if (cur == 0) return l;
                for (int i = 0; i < mat.size(); ++i)
                    for (int j = 0; j < mat[0].size(); ++j) {
                        unsigned nbr = flip(cur, mat.size(), mat[0].size(), i, j);
                        if (visited.insert(nbr).second)
                            q.push(nbr);
                    }
            }
            ++l;
        }
        
        return -1;
    }
};
