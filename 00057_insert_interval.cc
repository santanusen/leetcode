class Solution {
    // Binary search to find insert position.
    int get_insert_pos(vector<vector<int>>& intvs, vector<int>& nintv) {
        int l = 0, r = intvs.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nintv > intvs[m])
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Find the insert position through binary search.
        int i = get_insert_pos(intervals, newInterval);

        // Figure out how many intervals overlap with the new interval.
        int oi = i; // Index to start looking for overlaps towards right of new interval.
        int nol = 0; // Number of intervals overlapping with the new interval.

        // First, check if the interval to the immediate left of newInterval overlaps with it. 
        if (i > 0 && (intervals[i - 1][0] == newInterval[0] || intervals[i - 1][1] >= newInterval[0])) {
            --i; ++nol;
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }

        // Now check how many intervals to the right of the newInterval overlap with it.
        for (; oi < intervals.size(); ++oi) {
            if (intervals[oi][0] <= newInterval[1]) {
                newInterval[1] = max(intervals[oi][1], newInterval[1]);
                ++nol;
            } else
                break;
        }

        if (nol) { // We have overlaps. We can overwrite the first overalpping interval.
                intervals[i].swap(newInterval);
                if (nol > 1) { // More than one overlaps. Discard the extra overlapping intervals.
                    // Copy forward the non overlapping intervals.
                    int j = i + 1;
                    for (int k = i + nol; k < intervals.size(); ++k, ++j)
                        intervals[j].swap(intervals[k]);
                    // Discard the extra intervals.
                    intervals.erase(intervals.begin() + j, intervals.end());
                }
        } else { // No overlap. Intervals size will be increased by one.
            // First, add the new interval at the end.
            intervals.push_back(newInterval);

            // Now bring it forward to its correct position.
            for (int j = intervals.size() - 1; j > i; --j)
                intervals[j - 1].swap(intervals[j]);
        }
        
        return intervals;
    }
};
