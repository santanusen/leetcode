class DJS {
private:
    int *grp;
    int *rnk;
    int ngrps;

public:
    DJS(int n) : grp(new int[n]), rnk(new int[n]), ngrps(n) {
        for (int i = 0; i < n; ++i) {
            grp[i] = i;
            rnk[i] = 0;
        }
    }

    int find(int x) {
        if (grp[x] != x)
            grp[x] = find(grp[x]);
        return grp[x];
    }

    bool join(int x, int y) {
        int gx = find(x), gy = find(y);
        if (gx == gy)
            return false;

        if (rnk[gx] > rnk[gy])
            grp[gy] = gx;
        else if (rnk[gy] > rnk[gx])
            grp[gx] = gy;
        else {
            grp[gy] = gx;
            ++rnk[gx];
        }

        --ngrps;
        return true;
    }

    int num_groups() {
        return ngrps;
    }
};

#if 0
class Solution {
    int krushkal(vector<vector<int>>& edges, DJS& djs, int excl) {
        int mstw = 0;
        for (int i = 0; i < edges.size() && djs.num_groups() > 1; ++i) {
            if (i != excl && djs.join(edges[i][0], edges[i][1])) {
                mstw += edges[i][2];
            }
        }
        return mstw;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(),
             [](vector<int>& v1, vector<int>& v2)->bool {
                 return v1[2] < v2[2];
        });

        DJS djs(n);
        int mstw = krushkal(edges, djs, -1);

        vector<vector<int>> ans(2, vector<int>());
        for (int i = 0; i < edges.size(); ++i) {
            DJS d(n);
            // Try excluding the edge.
            int stw = krushkal(edges, d, i);
            if (stw > mstw || d.num_groups() > 1) {
                    ans[0].push_back(edges[i][3]);
            } else {
                // Try including the edge.
                DJS d2(n);
                d2.join(edges[i][0], edges[i][1]);
                int stw = edges[i][2] + krushkal(edges, d2, i);
                if (stw == mstw)
                    ans[1].push_back(edges[i][3]);
            }
        }

        return ans;
    }
};

#else

class Solution {
    int krushkal(vector<vector<int>>& edges, DJS& djs, vector<bool>& selected) {
        int mstw = 0;
        for (int i = 0; i < edges.size() && djs.num_groups() > 1; ++i) {
            if (!selected[i] && djs.join(edges[i][0], edges[i][1])) {
                selected[i] = true;
                mstw += edges[i][2];
            }
        }

        return mstw;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(),
             [](vector<int>& v1, vector<int>& v2)->bool {
                 return v1[2] < v2[2];
        });

        vector<bool> selected(edges.size());
        DJS djs(n);
        int mstw = krushkal(edges, djs, selected);

        vector<vector<int>> ans(2, vector<int>());
        for (int i = 0; i < edges.size(); ++i) {
            DJS d(n);
            vector<bool> sel(edges.size());
            if (selected[i]) {
                // Try excluding the edge.
                sel[i] = true;
                int stw = krushkal(edges, d, sel);
                if (stw > mstw || d.num_groups() > 1)
                    ans[0].push_back(edges[i][3]);
                else
                    ans[1].push_back(edges[i][3]);
            } else {
                // Try including the edge.
                sel[i] = true;
                d.join(edges[i][0], edges[i][1]);
                int stw = edges[i][2] + krushkal(edges, d, sel);
                if (stw == mstw)
                    ans[1].push_back(edges[i][3]);
            }
        }

        return ans;
        
    }
};
#endif

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
