class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        vector <unordered_map<long long /* diff */, int /* count */>> cnt(n);
        
        for (int i = 1; i < n; ++i){
            for (int j = 0; j < i; ++j) {
                long long diff = (long long) nums[i] - (long long) nums[j];
                int sum = 0;
                if (cnt[j].find(diff) != cnt[j].end()) {
                    sum = cnt[j][diff];
                }
                cnt[i][diff] += (sum + 1);
                ans += sum;
            }
        }
        
        return (int) ans;
    }
    
    
    int numberOfArithmeticSlices2(vector<int>& nums) {
        list<list<int>> val_subseq;
        unordered_map<int, int> same_num;
        long nsub = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            list<list<int>> new_subseq;
            bool same = false;
            for (auto& l: val_subseq) {
                if (nums[*l.begin()] == nums[i]) {
                    if (!same) {
                        ++same_num[nums[i]];
                        same = true;
                    }
                    
                } else if (l.size() < 2 || (long(nums[*l.begin()]) - long(nums[*(++l.begin())]) == long(nums[*l.rbegin()]) - long(nums[i]))) {
                    auto l2 = l;
                    l2.push_back(i);
                    new_subseq.push_back(l2);
                    if (l2.size() > 2)
                        ++nsub;
                }
            }
            val_subseq.insert(val_subseq.end(), new_subseq.begin(), new_subseq.end());
            //if (!same_num.count(nums[i]))
                val_subseq.push_back(list<int> {i});
        }
        
        for (auto p : same_num) {
            int n = ++p.second;
            if (n > 2)
                nsub += (((1UL) << n) - 1 - n - (n * (n -1) / 2));
        }
        
        return int(nsub);
    }
};
