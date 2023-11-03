class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int top = 0;
        string push = "Push", pop = "Pop";
        vector<string> ans;
        for (auto val : target) {
            int missing = val - top - 1;
            top = val;
            while (missing--) {
                ans.push_back(push);
                ans.push_back(pop);
            }
            ans.push_back(push);
        }

        return ans;
    }
};
