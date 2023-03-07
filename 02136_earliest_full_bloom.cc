class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> gp;
        for (int i = 0; i < plantTime.size(); ++i)
            gp.push_back({growTime[i], plantTime[i]});
        sort(gp.begin(), gp.end(), greater<pair<int, int>>());

        int fbday = 0;
        int day = 0;
        for (auto [g, p] : gp) {
            day += p;
            fbday = max(fbday, day + g);
        }

        return fbday;
        
    }
};
