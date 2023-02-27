class Solution {
public:
    int minimumDeviation(vector<int>& a) {
            int n = a.size(); 
            int mn = INT_MAX;  
            for (int i = 0 ; i < n ; i++) {
                  if (a[i] & 1) a[i] *= 2;
                  mn = min(mn, a[i]);
            }

            for (int i = n - 1 ; i >= 0; i--) {
                  while (a[i] % 2 == 0 && a[i] / 2 >= mn)
                    a[i] >>= 1;
            }

            sort(a.begin(), a.end());

            int ans = a[n - 1] - a[0];
            int i = n - 1;
            while (a[i] % 2 == 0) { 
                  a[i] /= 2;
                  ans = min(ans, a[(i - 1 + n) % n] - a[i]); 
                  i = (i - 1 + n) % n;
            }

            return ans; 
    }

    int minimumDeviation1(vector<int>& nums) {
        priority_queue<int> q;
        int nmin = INT_MAX;
        for (auto n : nums) {
            if (n & 1) n <<= 1;
            q.push(n);
            nmin = min(nmin, n);
        }

        int devmin = INT_MAX;
        while (true) {
            int nn = q.top(); q.pop();
            devmin = min(devmin, nn - nmin);
            if (nn & 1)
                break;
            nn >>= 1;
            q.push(nn);
            nmin = min(nn, nmin);
        }

        return devmin;
    }

};
