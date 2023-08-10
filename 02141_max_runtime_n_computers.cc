class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long bsum = 0;
        for (auto b : batteries) bsum += b;

        long long l = 1, r = bsum / n;
        while (l < r) {
            long long m = r - (r - l) / 2;
            long long bextra = 0;
            for (long long b : batteries)
                bextra += min(b, m);
            
            if (bextra >= (m * n))
                l = m;
            else
                r = m - 1;
        }

        return l;
        
    }

    long long maxRunTime2(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end(), greater<int>());

        long long res = batteries[n - 1];
        if (n == batteries.size())
            return res;

        long long l = 0;
        for (int i = n; i < batteries.size(); ++i)
            l += batteries[i];

        long long p = n - 1, c = 1;
        while (true) {
            if (p == 0) {
                res += l / c;
                return res;
            }

            long long d = (batteries[p - 1] - batteries[p]) * c;
            if (l >= d) {
                l -= d;
                res = batteries[p - 1];
                ++c;
                --p;
            } else {
                res += l / c;
                return res;
            }
        }

        return res;
    }

};

auto _=[](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
