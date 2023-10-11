class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, finish;
        for (auto& f : flowers) {
            start.push_back(f[0]);
            finish.push_back(f[1] + 1);
        }
        sort(start.begin(), start.end());
        sort(finish.begin(), finish.end());

        for (int i = 0; i < people.size(); ++i) {
            auto p = people[i];
            int ns = upper_bound(start.begin(), start.end(), p) - start.begin();
            int nf = upper_bound(finish.begin(), finish.end(), p) - finish.begin();
            people[i] = ns - nf;
        }

        return people;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
