class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        //vector<int> pen(n + 1);
        int pen[n + 1];
        pen[0] = (customers[0] == 'N' ? 1 : 0);
        for (int i = 1; i < n; ++i)
            pen[i] = pen[i - 1] + (customers[i] == 'N' ? 1 : 0);

        //pen[n] = pen[n - 1];

        int imin = INT_MAX, ipos = n, cp = 0;
        for (int i = n; i > -1; --i) {
            if (i < n && customers[i] == 'Y')
                ++cp;
            pen[i] = (i > 0 ? pen[i - 1] : 0) + cp;
            if (pen[i] <= imin) {
                imin = pen[i];
                ipos = i;
            }
            
        }

        return ipos;
    }
};

auto _=[](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
