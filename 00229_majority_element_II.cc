class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0;
        int n1 = 0, n2 = 0;

        for (auto n : nums)
            if (c1 == 0 && n != n2) {
                c1 = 1;
                n1 = n;
            } else if (c2 == 0 && n != n1) {
                c2 = 1;
                n2 = n;
            } else if (n == n1)
                ++c1;
            else if (n == n2)
                ++c2;
            else {
                --c1;
                --c2;
            }

            c1 = 0;
            c2 = 0;

            for (auto n : nums)
                if (n == n1)
                    ++c1;
                else if (n == n2)
                    ++c2;

            int thr = nums.size() / 3;
            vector<int> ans;
            if (c1 > thr)
                ans.push_back(n1);
            if (c2 > thr)
                ans.push_back(n2);

            return ans;
    }

    vector<int> majorityElement1(vector<int>& nums) {
        int thr = nums.size() / 3;
        vector<int> ans;      
        unordered_map<int, int> freq;
        for (auto num : nums)
            if (++freq[num] > thr) {
                if (ans.empty())
                    ans.push_back(num);
                else if (ans[0] != num) {
                    ans.push_back(num);
                    break;
                }
            }

        return ans;
        
    }

      vector<int> majorityElement2(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto num : nums)
            ++freq[num];

        int thr = nums.size() / 3;
        vector<int> ans;
        for (auto& [n, f] : freq)
            if (f > thr)
                ans.push_back(n);

        return ans;
        
    }  
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
