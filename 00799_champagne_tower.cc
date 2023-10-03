class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur { 1.0 * poured};

        for (int r = 0; r < query_row; ++r) {
            vector<double> nxt(r + 2, 0.0);
            int gmax = min(r, query_glass) + 1;
            for (int g = 0; g < gmax; ++g) {
                double spill = (cur[g] - 1.0) / 2;
                if (spill > 0.0) {
                    nxt[g] += spill;
                    nxt[g + 1] = spill;
                }
            }

            cur.swap(nxt);
        }

        return min(cur[query_glass], 1.0);      
    }
};

//auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
