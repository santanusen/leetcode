class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {         
        const int n = nums.size();

        int l = 0;
        int r = 0;
        int flips = 1;
        int maxLen = 0;

        queue<int> zq;

        while (r < n) {
            if (nums[r] == 0) {
                zq.push(r);
                --flips;
            }

            if (flips < 0) {
                l = zq.front() + 1; zq.pop();
                ++flips;
            }

            maxLen = max(maxLen, r - l);
            ++r;
        }

        return maxLen;
    }

    int longestSubarray2(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int pref[n], suf[n], zids[n], zs = 0;

        if (!nums[0]) zids[zs++] = 0;

        pref[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == 0) {
                pref[i] = 0;
                zids[zs++] = i;
            } else {
                pref[i] = pref[i - 1] + 1;
            }
        }

        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i > -1; --i)
            suf[i] = (nums[i] == 0 ? 0 : suf[i + 1] + 1);

        if (zs == n) return 0;
        if (zs < 2) return n - 1;
        int ans = 0;
        for (int z = 0; z < zs; ++z) {
            int zid = zids[z];
            int l = (zid > 0 ? pref[zid - 1] : 0) +
                    (zid < n - 1 ? suf[zid + 1] : 0);
            ans = max(ans, l);
        }

        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return false;}();
