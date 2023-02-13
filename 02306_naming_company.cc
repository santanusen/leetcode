class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> tbl[26];
        for (auto i : ideas)
            tbl[i[0] - 'a'].insert(i.substr(1));

        long long ans = 0;
        for (int i = 0; i < 25; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                int olap = 0;
                for (auto& s : tbl[i])
                    if (tbl[j].find(s) != tbl[j].end())
                        ++olap;
                ans += 2LL * (tbl[i].size() - olap) * (tbl[j].size() - olap);
            }
        }

        return ans;
    }
};
