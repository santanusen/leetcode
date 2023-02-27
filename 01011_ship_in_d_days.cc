class Solution {
    bool canShip(vector<int>& weights, int smax, int days) {
        int tw = 0;
        for (auto w : weights) {
            if (tw + w > smax) {
                if (--days < 1) return false;
                tw = w;
            } else
                tw += w;
        }

        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;
        for (auto w : weights) {
            l = max(l, w);
            r += w;
        }
        if (days == 1) return r;
        if (weights.size() <= days) return l;

        while (l <= r) {
            int m = (l + r) / 2;
            if (canShip(weights, m, days)) r = m - 1;
            else l = m + 1;
        }

        return l;
        
    }
};
