class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        
        for (const auto& q : queries) {
            auto r2 = q[2] * q[2]; // r^2
            int inside = 0;
            for (const auto& p : points) {
                auto dx = p[0] - q[0];
                auto dy = p[1] - q[1];
                if (dx * dx + dy * dy <= r2) // (x1 - x2)^2 + (y1 - y2)^2 <= r^2
                    ++inside;
            }
            res.push_back(inside);
        }
        
        return res;
        
    }
};
