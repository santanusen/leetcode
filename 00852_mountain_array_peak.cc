class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;

        while (l < r) {
            auto m = l + ((r - l) >> 1);
            if (arr[m + 1] > arr[m])
                l = m + 1;
            else
                r = m;
        }

        return l;
    }

    int peakIndexInMountainArray2(vector<int>& arr) {
        uint64_t l = 0, r = arr.size() - 1;

        while (l <= r) {
            auto m = (l + r) >> 1;
            if (arr[m - 1] < arr[m] && arr[m + 1] < arr[m])
                return m;
            if (arr[m - 1] > arr[m])
                r = m;
            else
                l = m;
        }

        return -1;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
