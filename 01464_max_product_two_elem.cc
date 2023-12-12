class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l1 = INT_MIN, l2 = INT_MIN;
        for (auto num : nums) {
            if (num > l2) {
                l2 = num;
                if (l2 > l1)
                    swap(l1, l2);
            }
        }

        return (l1 - 1) * (l2 - 1);
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
