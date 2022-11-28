class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        const int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i)
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        
        map<int /*end_time*/, int /*profit*/> dp = {{0, 0}};
        for (const auto& job: jobs) {
            auto cur_pos = prev(dp.upper_bound(job[1]));
            int cur_prof = cur_pos->second + job[2];
            if (cur_prof > dp.rbegin()->second)
                dp[job[0]] = cur_prof;
        }
        
        return dp.rbegin()->second;
        
    }
};
