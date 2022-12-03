class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Chose the bigger and smaller array based on size.
        vector<int>& big = (nums1.size() > nums2.size() ? nums1 : nums2);
        vector<int>& sml = (nums1.size() > nums2.size() ? nums2 : nums1);
        
        int sl = 0, sr = sml.size() - 1, sm, bm;
        
        // Median position, aka, if we split the merged arrays into
        // left and right halves, how many elements should be in the left half.
        const int M = (nums1.size() + nums2.size() + 1) >> 1; // >> 1 means / 2
        
        bool found = false;
        while (!found) {
            // Split the arrays into halves
            // [0 : sm][sm+1 : sm.size()-1]
            // [0 : bm][bm+1 : bm.size()-1]
            
            // Guess a split position in the smaller array.
            sm = (sl + sr) >> 1;
            
            // Split the bigger array such that,
            // left half of merged array should have M elements.
            // (bm + 1) + (sm + 1) = M
            bm = M - sm - 2;
            
            if ((bm > -1) && (sm + 1 < sml.size()) && (sml[sm + 1] < big[bm])) {
                // We split too much into left of smaller array.
                sl = sm + 1;
            } else if ((sm > -1) && (bm + 1 < big.size()) && (big[bm + 1] < sml[sm])) {
                // You guessed it.
                sr = sm - 1;
            } else {
                // Bingo.
                found = true;
            }                
        }
        
        // Find the maximum element in the left half.
        int m1 = INT_MIN;
        if (sm > -1 && sm < sml.size())
            m1 = sml[sm];
        if (bm > -1 && bm < big.size())
            m1 = max(m1, big[bm]);
        
        if (((nums1.size() + nums2.size()) & 1)) // Odd Length    
            return (double) m1;
        
        // Even Length
        
        // Find the minimum element in the right half.
        ++bm; ++sm;
        int m2 = INT_MAX;
        if (sm > -1 && sm < sml.size())
            m2 = sml[sm];
        if (bm > -1 && bm < big.size())
            m2 = min(m2, big[bm]);
        
        return double (m1 + m2) / 2.0;
    }
};
