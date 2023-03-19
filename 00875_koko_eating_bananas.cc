class Solution {
    bool canFinishEating(vector<int>& piles, int speed, int deadline) {
        int time = 0;
        for (auto p : piles) {
            time += (1 + (p - 1) / speed); // ceiling division
            if (time > deadline) return false;
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());
        if (h == piles.size()) return r;
        int l = 1;

        while (l < r) {
            int m = (l + r) >> 1;
            if (canFinishEating(piles, m, h))
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};
