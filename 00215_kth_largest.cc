class Solution {
    int partition(vector<int>& nums, int l, int r) {
        if (l == r) return l;

        int pi = l + rand() % (r - l + 1);
        swap(nums[l], nums[pi]);
        int pivot = nums[l];
        pi = l++;

        while (l <= r) {
            while (l <= r && nums[l] <= pivot) ++l;
            while (l <= r && nums[r] >= pivot) --r;
            if (l < r)
                swap(nums[l], nums[r]);
        }

        swap(nums[pi], nums[r]);

        return r;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        k = nums.size() - k;

        while (l <= r) {
            int m = partition(nums, l, r);
            if (m == k)
                return nums[k];

            if (m > k)
                r = m - 1;
            else
                l = m + 1;
        }
        
        return -1;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
