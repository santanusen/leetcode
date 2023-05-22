static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        int n = obs.size();
        //vector<int> answer(n);
        int lis[n], ll = 0;
        for (int i = 0; i < n; ++i) {
            int idx = upper_bound(&lis[0], &lis[ll], obs[i]) - &lis[0];
            if (idx == ll) ++ll;
            lis[idx] = obs[i];
            obs[i] = idx + 1;
        }
        return obs;
    }

    vector<int> longestObstacleCourseAtEachPosition2(vector<int>& obs) {
        map<int, int, greater<int>> omap;
        omap[1] = obs[0];

        vector<int> res(obs.size());
        res[0] = 1;
        for (int i = 1; i < obs.size(); ++i) {
            int l = 1;
            for (auto& [len, oh] : omap)
                if (oh <= obs[i]) {
                    l = len + 1;
                    break;
                }
            res[i] = l;
            auto itr = omap.find(l);
            if (itr == omap.end() || itr->second > obs[i])
                omap[l] = obs[i];
        }

        return res;
    }
};
