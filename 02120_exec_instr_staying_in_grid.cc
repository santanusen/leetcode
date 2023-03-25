class Solution {
    int numExec(int x, int y, int n, const string& s, int pos) {
        int e = 0;
        for (; pos < s.size(); ++pos) {
            switch(s[pos]) {
                case 'L': if (--y < 0) return e; break;
                case 'R': if (++y >= n) return e; break;
                case 'U': if (--x < 0) return e; break;
                case 'D': if (++x >= n) return e ; break;
            }
            ++e;
        }
        return e;
    }

public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size(), h = m + n, v = m + n, x = startPos[0], y = startPos[1];
        vector<int> hor(2 * h, m), ver(2 * v, m), res(m);
        for (int i = m - 1; i > -1; --i) {
            hor[h] = ver[v] = i;
            switch (s[i]) {
                case 'L' : ++h; break;
                case 'R' : --h; break;
                case 'U' : ++v; break;
                case 'D' : --v; break;
            }
            res[i] = min({m,
                          hor[h - y - 1],
                          hor[h - y + n],
                          ver[v - x - 1],
                          ver[v - x + n]}) - i;
        }
        return res;
    }

    vector<int> executeInstructions_brute(int n, vector<int>& startPos, string s) {
        vector<int> res(s.size());
        int x = startPos[0], y = startPos[1];
        for (int pos = 0; pos < s.size(); ++pos)
            res[pos] = numExec(x, y, n, s, pos);

        return res; 
    }
};
