class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 1; i < points.size(); ++i)
            ans += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
        return ans;
    }
};

auto _=[](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
