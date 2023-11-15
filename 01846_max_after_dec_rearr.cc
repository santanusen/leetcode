class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging2(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int nmax = 0;
        for (auto num : arr)
            nmax = min(num, nmax + 1);
        return nmax;
    }

    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        int counts[n + 1];
        memset(counts, 0, (n + 1) * sizeof(int));
        
        for (int num : arr)
            ++counts[min(num, n)];
        
        int ans = 1;
        for (int num = 2; num <= n; num++)
            ans = min(ans + counts[num], num);
        
        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
