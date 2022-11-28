class Solution {
public:
    /*
    int sumSubarrayMinsDP(vector<int>& arr) {
        const int MOD = 1000000007;
        int DP[2][arr.size()];
        
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i)
            sum = (sum % MOD + (DP[0][i] = arr[i])) % MOD;
        
        
        for (int d = 1; d < arr.size(); ++d) {
            for (int i = 0; i < arr.size() - d; ++i)
                sum = (sum % MOD + (DP[d % 2][i + d] = min(DP[(d + 1) % 2][i + d - 1], DP[(d + 1) % 2][i + d]))) % MOD;
        }
            
        return sum;
        
    }*/
    
    
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1000000007;
        stack<int> s;
        long sum = 0;
        
        for (int i = 0; i <= arr.size(); ++i) {
            while (!s.empty() && (i == arr.size() || arr[s.top()] >= arr[i])) {
                long mid = s.top(); s.pop();
                long prev = (s.empty() ? -1: s.top());
                sum = (sum % MOD) + ((arr[mid] % MOD) * ((mid - prev) % MOD) * ((i - mid) % MOD));
            }
            
            s.push(i);
        }
        
        return static_cast<int>(sum % MOD);
    }
};
