class Solution {
public:

    string destCity2(vector<vector<string>>& paths) {
        unordered_set<string> ce;
        for (auto& p : paths)
            ce.insert(p[0]);
        for (auto& p : paths)
            if (ce.find(p[1]) == ce.end())
                return p[1];
        return "";
    }

    string destCity1(vector<vector<string>>& paths) {
        unordered_set<string> ce, cne;
        for (auto& p : paths) {
            cne.erase(p[0]);
            ce.insert(p[0]);

            if (ce.find(p[1]) == ce.end())
                cne.insert(p[1]);
        }

        return *cne.begin();

    }

    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> egr;
        for (auto& p : paths) {
            ++egr[p[0]];
            egr[p[1]] += 0;
        }

        for (auto& [city, ec] : egr)
            if (ec == 0)
                return city;

        return "";
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
