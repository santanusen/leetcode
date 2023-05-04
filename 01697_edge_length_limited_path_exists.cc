class Solution {
    static bool vec_less(const vector<int>& v1, const vector<int>& v2) {
        return v1[2] < v2[2];
    }

    class UnionFind {
        vector<int> group;
        vector<int> rank;

        public:
        UnionFind (int n) : group(n), rank(n, 0) {
            for (int i = 0; i < n; ++i)
                group[i] = i;
        }

        int find(int x) {
            int px = group[x];
            if (px != x)
                group[x] = find(px);
            return group[x];
        }

        void join(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return;

            if (rank[px] < rank[py])
                group[px] = py;
            else if (rank[py] < rank[px])
                group[py] = px;
            else {
                group[px] = py;
                ++rank[px];
            }
        }
    };

public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        //vector<vector<int>> queries;
        for (int i = 0; i < queries.size(); ++i) {
            //queries.push_back(oqueries[i]);
            queries[i].push_back(i);
        }
        sort(edgeList.begin(), edgeList.end(), vec_less);
        sort(queries.begin(), queries.end(), vec_less);

        vector<bool> ans(queries.size(), false);
        UnionFind u(n);
        int ei = 0;
        for (auto &q : queries) {
            int wlim = q[2];
            while (ei < edgeList.size() && edgeList[ei][2] < wlim) {
                u.join(edgeList[ei][0], edgeList[ei][1]);
                ++ei;
            }
            if (u.find(q[0]) == u.find(q[1]))
                ans[q[3]] = true;
        }

        return ans;
    }
};
