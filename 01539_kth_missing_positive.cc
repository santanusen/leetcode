class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        // miss_within_array = (an - a0 + 1 - n) ........ (1)

        // miss_till_array_end
        //  = miss_before_array + miss_within_array
        //  = (a0 - 1) + miss_within_array
        //  = a0 - 1 + an - a0 + 1 - n
        //  = an - n; ................ (2)

        // kth_missing    [Assuming k-th missing is beyond array end]
        //  = (an + (k - miss_till_array_end))
        //  = an + k - an + n
        //  = k + n; ............... (3)


        // k-th missing is before array start.
        if (k < arr[0]) return k;

        int n = arr.size();
        // k-th missing is beyond array end.                
        if (k > arr[n - 1] - n) return k + n; // Eqn (3)

        // k-th missing is within array: Binary search
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m] - m - 1 < k) // Eqn (2)
                l = m + 1;
            else
                r = m - 1;
        }

        // At the end of the binary search, r will point to
        // the array index where total missing is just below
        // or equal to k.
        return k + r + 1; // Eqn (3)
        
    }
};
