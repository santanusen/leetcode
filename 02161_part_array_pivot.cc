class Solution {
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        const int N = nums.size();
        vector<int> res(N, pivot);
        for (int i = 0, l = 0, r = N - 1; i < N; ++i) {
            if (nums[i] < pivot) // Fill front
                res[l++] = nums[i];
            if (nums[N - 1- i] > pivot) // Fill back
                res[r--] = nums[N - 1 - i];
        }
        
        return res;
        
    }
};

