    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 1;
        int is = points[0][0], ie = points[0][1];
        for (auto& p : points) {
            if ((p[0] >= is && p[0] <= ie) ||
                (p[1] >= is && p[1] <= ie) ||
                (p[0] <= is && p[1] >= ie)) {
                    is = max(is, p[0]);
                    ie = min(ie, p[1]);
                } else {
                    ++count;
                    is = p[0];
                    ie = p[1];
                }
        }
        return count;
    }

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 1;
        int ilast = points[0][1];
        for (auto& p : points) {
            if (p[0] > ilast) {
                    ++count;
                    ilast = p[1];
            } else
                ilast = min(ilast, p[1]);
        }
        return count;
    }
};

