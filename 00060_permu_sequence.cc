class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) return "1";
        
        int fact = 1;
        vector<int> nums(n);
        for (int i = 1; i < n; ++i) {
            fact *= i;
            nums[i - 1] = i;
        }
        nums[n - 1] = n;

        k = k - 1;
        string ans;
        while (true) {
            int i = k / fact;
            ans += ('0' + nums[i]);
            nums.erase(nums.begin() + i);
            if (nums.empty()) break;
            k %= fact;
            fact /= nums.size();
        }

        return ans;

    }

    string getPermutation2(int n, int k) {
        string nums(n, '\0');
        for (int i = 0; i < n; ++i)
            nums[i] = '1' + i;

        while (--k) {
            int i = nums.size() - 2;
            while (i > -1 && !(nums[i] < nums[i + 1])) --i;
            if (i > -1) {
                int j = nums.size() - 1;
                while (j > i && !(nums[j] > nums[i])) --j;
                swap(nums[i], nums[j]);
            }
            reverse(nums.begin() + i + 1, nums.end());
        }

        return nums;
    }
};
