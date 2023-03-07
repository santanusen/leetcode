class Solution {
    bool isTripPossible(vector<int>& time, int totalTrips, long long deadline) {
        long long ntrips = 0;
        for (int t : time)
            if ((ntrips += (deadline / t)) >= totalTrips)
                return true;

        return false;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        if (time.size() == 1) return (long long)(totalTrips) * time[0];
        long long l = 1, r = 1LL * (totalTrips) * *min_element(time.begin(), time.end());

        while (l < r) {
            long long m = (l + r) / 2;
            if (isTripPossible(time, totalTrips, m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
