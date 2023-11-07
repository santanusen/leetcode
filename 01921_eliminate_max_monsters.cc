class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        double arrival[n];
        for (int i = 0; i < n; ++i)
            arrival[i] = (double(dist[i]) / speed[i]);
        sort(arrival, arrival + n);

        int ans = 0;
        for (int i = 0; i < n && arrival[i] > ans; ++i)
            ++ans;

        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
