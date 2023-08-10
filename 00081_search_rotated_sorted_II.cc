class Solution {
    const int LTHR = INT_MAX;

    bool linear_search(vector<int>& nums, int l, int r, int target) {
        while (l <= r)
            if (nums[l++] == target)
                return true;
        return false;
    }

    bool canBinSearch(vector<int>& nums, int s, int val) {
        return nums[s] != val;
    }

    bool valInFirst(vector<int>& nums, int s, int val) {
        return nums[s] <= val;
    }

public:
    bool search(vector<int>& nums, int target) {
#if 1
        if (nums.empty()) return false;

        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (r - l <= LTHR)
                return linear_search(nums, l, r, target);

            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return true;

            if (!canBinSearch(nums, l, nums[m])) {
                ++l;
            } else {
                bool mInF = valInFirst(nums, l, nums[m]);
                bool tInF = valInFirst(nums, l, target);

                if (mInF != tInF) {
                    if (mInF)
                        l = m + 1;
                    else
                        r = m - 1;
                } else {
                    if (target > nums[m])
                        l = m + 1;
                    else
                        r = m - 1;
                }
            }
        }

        return false;

#else
        return linear_search(nums, 0, nums.size() - 1, target);
#endif
        
    }
};

auto _=[](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
