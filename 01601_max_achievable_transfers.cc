class Solution {
    int tmax = 0;

    void dfs(vector<vector<int>>& reqs, vector<int8_t>& balance, int pos, int trans) {
        if (pos == reqs.size()) {
            for (auto b : balance)
                if (b != 0)
                    return;
            tmax = max(tmax, trans);
            return;
        }
        if (trans + reqs.size() - pos <= tmax) // Can't improve
            return;

        --balance[reqs[pos][0]];
        ++balance[reqs[pos][1]];
        dfs(reqs, balance, pos + 1, trans + 1);
        ++balance[reqs[pos][0]];
        --balance[reqs[pos][1]];

        dfs(reqs, balance, pos + 1, trans);
    }

public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int8_t> balance(n, 0);
        dfs(requests, balance, 0, 0);    
        return tmax;
    }

    int maximumRequests_dp(int n, vector<vector<int>>& requests) {
        int ans = 0;

        int M = (1 << requests.size());
        for (int tmap = 0; tmap < M; ++tmap) {
            vector<int8_t> balance(n, 0);
            int trans = __builtin_popcount(tmap);
            if (trans <= ans) continue; // Can't improve

            for (int cur = tmap, pos = requests.size() - 1; cur != 0; cur >>= 1, --pos) {
                if (cur & 1) {
                    --balance[requests[pos][0]];
                    ++balance[requests[pos][1]];
                }
            }

            bool valid = true;
            for (auto b : balance)
                if (b) {
                    valid = false;
                    break;
                }

            if (valid)
                ans = trans;
        }

        return ans;
    }
};

auto _ = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return false;}();
