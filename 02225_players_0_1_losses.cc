class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> losses;
        for (auto& match : matches) {
            losses[match[0]] += 0;
            losses[match[1]] += 1;
        }
        
        vector<vector<int>> res(2);
        for (auto& l : losses)
            if (l.second < 2)
                res[l.second].push_back(l.first);
        
        return res;
        
    }
};
