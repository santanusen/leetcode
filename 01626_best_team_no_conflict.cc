class Solution {

public:

#define LSB(i) ((i) & -(i))

    int queryBIT(vector<int>& BIT, int i) {
        int smax = INT_MIN;
        for(; i > 0; i -= LSB(i))
            smax = max(smax, BIT[i]);
        return smax;
    }

    void updateBIT(vector<int>& BIT, int i, int val) {
        for (; i < BIT.size(); i += LSB(i))
            BIT[i] = max(val, BIT[i]);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players; // <score, age>
        int maxage = 0;
        for (int i = 0; i < scores.size(); ++i) { 
            players.push_back({scores[i], ages[i]});
            maxage = max(ages[i], maxage);
        }
        sort(players.begin(), players.end());

        int ans = 0;
        vector<int> BIT(maxage + 1, 0);
        for (auto& p : players) {
            int curBest = queryBIT(BIT, p.second) + p.first;
            updateBIT(BIT, p.second, curBest);
            ans = max(ans, curBest);
        }

        return ans;
        
    }

private:

    int dfs(vector<pair<int, int>>& players, vector<vector<int>>& dp,
             int pidx, int idx) {
        if (idx >= players.size()) return 0; // No more players remain
        if (dp[pidx + 1][idx] != -1) return dp[pidx + 1][idx]; // Already calculated

        int res = 0;
        // Include this player if possible
        if (pidx == -1 || players[pidx].second <= players[idx].second)
                res = players[idx].second + dfs(players, dp, idx, idx + 1);

        // Without including this player
        res = max(res, dfs(players, dp, pidx, idx + 1));
        return dp[pidx + 1][idx] = res;
    }

    int bestTeamScore_memo(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players; // <age, score>
        for (int i = 0; i < scores.size(); ++i) 
            players.push_back({ages[i], scores[i]});
        sort(players.begin(), players.end());

        vector<vector<int>> dp(scores.size(), vector<int>(scores.size(), -1));
        return dfs(players, dp, -1, 0);
    }

    int bestTeamScore_dp(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players; // <age, score>
        for (int i = 0; i < scores.size(); ++i) 
            players.push_back({ages[i], scores[i]});
        sort(players.begin(), players.end());

        int res = 0;
        vector<int> dp(players.size());
        for (int i = 0; i < players.size(); ++i) {
            dp[i] = players[i].second;
            res = max(res, dp[i]);
        }
        for (int i = 0; i < players.size(); ++i) {
            for (int j = i - 1; j > -1; --j) // Players i and j can be in the same team
                if (players[j].second <= players[i].second)
                    dp[i] = max(dp[i], dp[j] + players[i].second);
                res = max(res, dp[i]);
        }

        return res;
    }

};
