class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = people.size(), m = req_skills.size();

        unordered_map<string, int> skid;
        for (int i = 0; i < m; ++i)
            skid[req_skills[i]] = i;

        vector<int> psk(n);
        for (int i = 0; i < n; ++i)
            for (string s : people[i])
                psk[i] |= (1 << skid[s]);

        int rsk = (1 << m);
        vector<uint64_t> dp(rsk, -1);

        function<uint64_t (int)> dfs =
        [&] (int skm) -> uint64_t {
            if (skm == 0) return 0;
            if (dp[skm] != -1) return dp[skm];

            for (int i = 0; i < n; ++i) {
                int sskm = skm & ~psk[i];
                if (sskm != skm) {
                    uint64_t pmask = dfs(sskm) | (1LL << i);
                    if (dp[skm] == -1 ||
                        __builtin_popcountll(pmask) < __builtin_popcountll(dp[skm]))
                            dp[skm] = pmask;
                }
            }

            return dp[skm];
        };

        uint64_t amask = dfs(rsk - 1);
        vector<int> ans;

        for (int i = 0; i < n; ++i)
            if ((amask >> i) & 1)
                ans.push_back(i);

        return ans;

    }
};

class Solution_DP {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = people.size(), m = req_skills.size();

        unordered_map<string, int> skid;
        for (int i = 0; i < m; ++i)
            skid[req_skills[i]] = i;

        vector<int> psk(n);
        for (int i = 0; i < n; ++i)
            for (string s : people[i])
                psk[i] |= (1 << skid[s]);

        int rsk = (1 << m);
        vector<uint64_t> dp(rsk, (1LL << n) - 1);
        dp[0] = 0;

        for (int skm = 1; skm < rsk; ++skm) {
            for (int i = 0; i < n; ++i) {
                int sskm = skm & ~psk[i];
                if (sskm != skm) {
                    uint64_t pmask = dp[sskm] | (1LL << i);
                    if (__builtin_popcountll(pmask) < __builtin_popcountll(dp[skm]))
                        dp[skm] = pmask;
                }
            }
        }

        uint64_t amask = dp[(1 << m) - 1];
        vector<int> ans;

        for (int i = 0; i < n; ++i)
            if ((amask >> i) & 1)
                ans.push_back(i);

        return ans;
    }
};

class Solution_BT {
    uint64_t apmask;

    void dfs(vector<pair<int, uint16_t>>& pskl, uint16_t rskmap, uint16_t cskmap, int pos, uint64_t pmask) {
        if (rskmap == cskmap) {
            if (__builtin_popcountll(apmask) > __builtin_popcountll(pmask))
                apmask = pmask;
            return;
        }

        if (pos == pskl.size() || __builtin_popcountll(apmask) <= __builtin_popcountll(pmask))
            return;


        uint16_t ncskmap = cskmap | pskl[pos].second;
        if (ncskmap != cskmap) {
            dfs(pskl, rskmap, ncskmap, pos + 1, pmask | (1LL << pskl[pos].first));
        }

        dfs(pskl, rskmap, cskmap, pos + 1, pmask);
    }

public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {

        uint16_t rskmap =  0;
        unordered_map<string, int> skid;
        for (int i = 0; i < req_skills.size(); ++i) {
            skid[req_skills[i]] = i;
            rskmap |= (1 << i);
        }

        apmask = 0LL;
        vector<pair<int, uint16_t>> pskl;
        unordered_set<uint16_t> visited;
        for (int i = 0; i < people.size(); ++i) {
            uint16_t skmap = 0;
            for (auto s : people[i])
                skmap |= (1 << skid[s]);
            if (visited.find(skmap) == visited.end()) {
                pskl.push_back({i, skmap});
                apmask |= (1LL << i);
                visited.insert(skmap);
            }
        }

        sort(pskl.begin(), pskl.end(),
             [](pair<int, uint16_t>& a, pair<int, uint16_t>& b) -> bool {
                return __builtin_popcount(a.second) > __builtin_popcount(b.second);
             });

        dfs(pskl, rskmap, 0, 0, 0);
                vector<int> ans;

        for (int i = 0; i < people.size(); ++i)
            if ((apmask >> i) & 1)
                ans.push_back(i);

        return ans;

    }
};

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();
