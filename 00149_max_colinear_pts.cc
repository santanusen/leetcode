class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) return points.size();
        int ans = 0;
        for (int i = 0; i + 1 < points.size(); ++i) {
                unordered_map<double, int> slopes; // Number of segments with same slope (dy/dx).
                int vert = 0; // Vertical line segments (dx = 0).
            for (int j = i + 1; j < points.size(); ++j) {
                ans = (points[i][0] == points[j][0]) ?
                        max(++vert, ans) :
                        max(++slopes[double(points[i][1] - points[j][1]) / (points[i][0] - points[j][0])], ans);
            }
            if (ans + 1 > (points.size()) / 2) break; // More than half the points on the
                                                          // same line. Can't improve on that.
        }
        return ans + 1; // #points = #segments + 1
    }
};

