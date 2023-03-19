class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        //sort(points.begin(), points.end(), [](vector<int>& l, vector<int>& r) -> bool {return l[0] < r[0];});
        set<int> px;
        for (auto& p : points)
            px.insert(p[0]);

        int d = 0;
        for (auto cur = px.begin(), prv = cur++; cur != px.end(); prv = cur++)
            d = max(d, *cur - *prv);
        return d;
    }
};
