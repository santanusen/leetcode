class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        for (int l = 0, r = 1, w = 0; r < n; ++r) {
            if (arr[l] > arr[r]) {
                ++w;
            } else {
                l = r;
                w = 1;
            }

            if (w == k)
                return arr[l];

            if (n - r - 1 + w < k)
                break;
        }

        return *max_element(arr.begin(), arr.end());
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
