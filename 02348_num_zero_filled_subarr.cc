class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0, contig = 0;
        for (auto n : nums)
            res += (contig = (n == 0) ? contig + 1 : 0);
        return res;
    }
};
