class DJS {
    vector<int> group, rank;

public:
    DJS(int n) : rank(n) {
        for (int i = 0; i < n; ++i)
            group.push_back(i);
    }

    int Find(int x) {
        if (group[x] != x)
            group[x] = Find(group[x]);
        return group[x];
    }

    bool Join(int x, int y) {
        int gx = Find(x);
        int gy = Find(y);

        if (gx == gy)
            return false;

        if (rank[gx] > rank[gy])
            group[gy] = gx;
        else if (rank[gy] > rank[gx])
            group[gx] = gy;
        else {
            group[gy] = gx;
            ++rank[gx];
        }
        return true;
    }
};

class Solution_Kruskal {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 2)
            return 0;

        vector<vector<int>> edges;

        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                edges.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), 
                                 i, j});

        sort(edges.begin(), edges.end());

        DJS d(n);
        int ans = 0, nc = n;
        for (auto& e : edges) {
            if (d.Join(e[1], e[2])) {
                ans += e[0];
                if (--nc == 1)
                    break;
            }
        }

        return ans;

    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int idx[n];
        int cost[n];
        iota(idx, idx + n, 0);
        /* init cost to max value: cost[i]: minimal cost connecting point[i] to one point among the rest */
        memset(cost, 0x7f, sizeof(int) * n);
        int pivot = 0, minCost = 0, ans = 0;
        while (n) {
            ans += minCost;
            /* pivot point, where cost of connection to all reamining points is calculated */
            int x = points[idx[pivot]][0], y = points[idx[pivot]][1];
            /* move to separate pivot location from those of remaining points */
            swap(idx[pivot], idx[--n]);
            minCost = INT_MAX;
            /* find the min cost of connection b/w pivot points and remaining points */
            for (int i = 0; i < n; i++) {
                auto &p = points[idx[i]];
                auto &c = cost[idx[i]];
                c = min(c, abs(p[0] - x) + abs(p[1] - y));
                if (c < minCost) {
                    pivot = i;
                    minCost = c;
                }
            }
        }
        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
