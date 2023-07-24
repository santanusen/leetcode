class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> slen;
        int lmax = 0;

        for (auto n : arr) {
            auto itr = slen.find(n - difference);
            int l = 1 + (itr != slen.end() ? itr->second : 0);
            lmax = max(lmax, l);
            slen[n] = l;
        }

        return lmax;
        
    }
};

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return false;}();
