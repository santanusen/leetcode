class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b) -> bool {return a[1] < b[1];});

        int ans = 0;
        int k = INT_MIN;

        for (auto& intv : intervals) {
            if (intv[0] >= k) // Case 1
                k = intv[1];
            else // Case 2
                ans++;
        }
        
        return ans;
    }

    int eraseOverlapIntervals2(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n < 2) return 0;

        sort(intervals.begin(), intervals.end());

        int ni = 0;

        int i = 0, j = 1;
        while (i < n) {
            if (j >= n || intervals[i][1] <= intervals[j][0]) { // No overlap
                // i included. j tested for next
                ++ni;
                i = j;
                ++j;
            } else { // Overlap
                // Choose interval that ends first.
                if (intervals[j][1] < intervals[i][1])
                    i = j;
                j = j + 1;
            }
        }

        return n - ni;
    }
};

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();
