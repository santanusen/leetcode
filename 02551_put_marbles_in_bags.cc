class Solution {
public:
  long long putMarbles(vector<int>& weights, int k) {
    --k;
    if (k == 0) return 0;

    int len = weights.size();
    long nearSum[len - 1];

    for (int i = 0; i < len - 1; ++i)
      nearSum[i] = weights[i] + weights[i + 1];

    sort(&(nearSum[0]), &(nearSum[len - 1]));

    long ret = 0;
    for (int i = 0; i < k; ++i)
      ret -= nearSum[i];

    for (int i = len - 2; i > len - 2 - k; --i)
      ret += nearSum[i];

    return ret;
  }

    long long putMarbles1(vector<int>& v, int k) {
            if (k < 2) return 0;
            int n = v.size();
            long long  mx = v[0] + v[n-1]; // Maximum Value 
            long long  mn = v[0] + v[n-1]; // Minimum Value
            
            vector<long long > adjSum; // For storing adjacent sum

            for(int i = 0;i<n-1;i++)
                    adjSum.push_back(v[i] + v[i+1]);  // Storing adjacent sum
            
            sort(adjSum.begin(),adjSum.end(),greater<int>()); // Sorting in descending order
            
            for(int i = 0;i<k-1;i++)
                    mx +=(long long) adjSum[i], // adding maximum to mx
                    mn +=(long long) adjSum[n-i-2]; // adding minimum to mn
            
            return (mx- mn); // difference is the answer   
    }

    long long putMarbles2(vector<int>& weights, int k) {
        if (k < 2) return 0;
        long long smax = 0, smin = 0;
        priority_queue<long long> wmin;
        priority_queue<long long, vector<long long>, greater<long long>> wmax;

        int n = weights.size();
        for (int i = 0; i < n - 1; ++i) {
            int wsum = weights[i] + weights[i + 1];
            if (i < k - 1 || wmax.empty()) {
                wmax.push(wsum);
                smax += wsum;

                wmin.push(wsum);
                smin += wsum;
            } else {
                if (wsum < wmin.top()) {
                    smin -= wmin.top(); wmin.pop();
                    smin += wsum;
                    wmin.push(wsum);
                }
                if (wsum > wmax.top()) {
                    smax -= wmax.top(); wmax.pop();
                    smax += wsum;
                    wmax.push(wsum);
                }
            }
        }
        
        return smax - smin;
    }
};

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();
