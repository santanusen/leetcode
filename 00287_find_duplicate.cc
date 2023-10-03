class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //int n = nums.size();
        int slow = 0, fast = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }

        int cpos = 0;
        while (true) {
            slow = nums[slow];
            cpos = nums[cpos];
            if (slow == cpos)
                break;
        }

        return cpos;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
