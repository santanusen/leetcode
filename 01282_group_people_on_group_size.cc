class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> grps;
        vector<vector<int>> ans;

        for(int i = 0; i < groupSizes.size(); i++)
            grps[groupSizes[i]].push_back(i);

        for(auto it : grps) {
            vector<int> temp;
            for (int i = 0, cnt = 0; i < it.second.size(); i++) {
                temp.push_back(it.second[i]);
                if (++cnt == it.first) {
                    ans.push_back(temp);
                    temp.clear();
                    cnt = 0;
                }
            }
        }

        return ans;
    }

    vector<vector<int>> groupThePeople2(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> grps;
        vector<vector<int>> ans;

        for (int i = 0; i < groupSizes.size(); ++i) {
            auto gsz = groupSizes[i];
            if (gsz == 1)
                ans.push_back({i});
            else {
                grps[gsz].push_back(i);
                if (grps[gsz].size() == gsz) {
                    vector<int> ngrp;
                    ngrp.swap(grps[gsz]);
                    ans.push_back(ngrp);
                }
            }
        }

        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
