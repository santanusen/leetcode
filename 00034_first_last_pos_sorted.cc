class Solution {
    int bsearch(vector<int>& nums, int l, int r, int target) {
        if (l < 0 || r + 1 > nums.size()) return -1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] == target) return m;
            if (target < nums[m]) r =  m - 1;
            else l = m + 1;
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        int pos = bsearch(nums, 0, nums.size() - 1, target);
        if (pos == -1) return {-1, -1};

        int lpos = pos, rpos = pos, tpos;
        while ((tpos = bsearch(nums, 0, lpos - 1, target)) != -1)
            lpos = tpos;
        while ((tpos = bsearch(nums, rpos + 1, nums.size() - 1, target)) != -1)
            rpos = tpos;

        return {lpos, rpos};
    }
}
