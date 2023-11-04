class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        return max((right.empty() ? 0 : n - *min_element(right.begin(), right.end())),
                   (left.empty() ? 0 : *max_element(left.begin(), left.end())));
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
