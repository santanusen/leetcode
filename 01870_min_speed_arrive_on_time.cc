class Solution {
    bool can_arrive(vector<int>& dist, double hour, int speed) {
        double ttime = 0;
        int n = dist.size();
        for (int i = 0; i < n - 1; ++i) {
            ttime += ((dist[i] + speed - 1) / speed);
            if (ttime >= hour)
                return false;
        }

        if (((double)(dist[n - 1])) - (hour * speed - ttime * speed) > 0.00001)
            return false;

        return true;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= n - 1) return -1;

        int l = 1, r = *max_element(dist.begin(), dist.end());
        if ((int)hour == n - 1) {
            r = max(r,
                    (int)(ceil(dist[n - 1] / (hour - (int)(hour)))));
        }

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (can_arrive(dist, hour, m))
                r = m - 1;
            else
                l = m + 1;
        }

        return l;
    }
};

auto _=[](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
