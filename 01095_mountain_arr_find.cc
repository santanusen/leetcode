/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // find peak.
        int l = 0, r = n - 1, peak = -1;
        while (l <= r) {
            peak = (l + r) / 2;
            int pp = (peak > 0 ? mountainArr.get(peak - 1) : INT_MIN);
            int pc = mountainArr.get(peak);
            int pn = (peak + 1 < n ? mountainArr.get(peak + 1) : INT_MIN);
            if (pc > pp && pc > pn)
                break;
            if (pn > pc)
                l = peak + 1;
            else
                r = peak - 1;
        }

        // find in left half
        l = 0;
        r = peak;
        while (l <= r) {
            int m = (l + r) / 2;
            int val = mountainArr.get(m);
            if (val == target)
                return m;
            if (val < target)
                l = m + 1;
            else
                r = m - 1;
        } 

         // find in right half
        l = peak + 1;
        r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int val = mountainArr.get(m);
            if (val == target)
                return m;
            if (val > target)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;
        
    }
};
