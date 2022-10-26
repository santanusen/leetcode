class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> grp;
        
        for (int i = 0; i < groupSizes.size(); ++i) {
            grp[groupSizes[i]].push_back(i);
            if (grp[groupSizes[i]].size() == groupSizes[i]) {
                vector<int> g;
                g.swap(grp[groupSizes[i]]);
                res.push_back(g);
            }
        }
        
        return res;
        
    }
};
