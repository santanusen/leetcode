class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mval = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        for (auto c : candies) res.push_back(extraCandies + c >= mval);
        return res;
    }
};
