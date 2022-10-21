class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int k = m + n - 1;
        --m; --n;
        while (n > -1) {
            nums1[k] = (m > -1) ? nums1[m]: INT_MIN;
            if (n > -1 && nums2[n] > nums1[k]) {
                nums1[k] = nums2[n--];
            } else {
                --m;
            }
            --k;
        }    
    }
};
