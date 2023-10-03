class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        for (auto num : nums)
            if (l < 2 || nums[l - 2] != num)
                nums[l++] = num;
                
        return l;
    }

    int removeDuplicates2(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return n;

        int l = 0;
        int stk[2], stkl = 0;

        for (auto num: nums) {
            if (stkl == 0)
                stk[stkl++] = num;
            else {
                if (stk[stkl - 1] == num) {
                    if (stkl < 2)
                        stk[stkl++] = num;
                } else {
                    while (stkl != 0) {
                        nums[l++] = stk[--stkl];
                    }
                    stk[stkl++] = num;
                }
            }
        }

        while (stkl != 0) {
            nums[l++] = stk[--stkl];
        }

        return l;
        
    }
};

auto _=[](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
