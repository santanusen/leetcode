class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Set the left and right boundaries
        int left = 0, right = int(nums.size());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (left > 0 and nums[left - 1] == target) {
            return left - 1;
        } else {
            return -1;
        }
    }
    
    int search_stl(vector<int>& n, int t) {
        int ind = lower_bound(n.begin(),n.end() , t) - n.begin();
        if(ind < n.size() && n[ind]==t ) return ind;
        return -1;
    }

    int search2(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int d = nums[r] - nums[l];
            int m = (d == 0) ? (l + r) / 2 : l + (r - l) * (target - nums[l]) / d;
            int x = nums[m];
            if (x == target) return m;
            if (target < x) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
};
