class Solution {
    struct MyHash {
        size_t operator()(const std::vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v)
                seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }

        size_t operator()(const std::pair<int, int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            seed ^= hasher(v.first) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= hasher(v.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

    vector<vector<int>> fourSum2(vector<int>& nums, int target) {
        unordered_map<long, list<pair<int, int>>> smap;
        unordered_map<long, unordered_set<vector<int>, MyHash>> svmap;

        unordered_set<vector<int>, MyHash> res;

        for (int i = 0; i + 1 < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j) {
                long sum = (long)nums[i] + nums[j];
                long tsum = (long)target - sum;
                auto itr = smap.find(tsum);
                if (itr != smap.end()) {
                    for (auto& [k, l] : itr->second) {
                        if (i != k && j != k && i != l && j != l) {
                            vector<int> quad {nums[i], nums[j], nums[k], nums[l]};
                            sort(quad.begin(), quad.end());
                            res.insert(quad);
                        }
                    }
                }
                vector<int> vpair {nums[i], nums[j]};
                sort(vpair.begin(), vpair.end());
                if (svmap[sum].insert(vpair).second)
                    smap[sum].push_back({i, j});
            }

        return vector<vector<int>>(res.begin(), res.end());
    }

    vector<vector<int>> threeSum(vector<int>& nums, int N, long target, int cval, vector<vector<int>>& res) {
        target = target - cval;
        for (int i = 0; i + 2 < N; ++i) {
            long tgt = target - nums[i];
            int l = i + 1, r = N - 1;
            while (l < r) {
                long sum = (long) nums[l] + nums[r];
                if (sum < tgt) ++l;
                else if (sum > tgt) --r;
                else {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r], cval});
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    ++l;
                    while (l < r && nums[r] == nums[r - 1]) --r;
                    --r;
                }
            }
            while (i + 1 < N && nums[i] == nums[i + 1]) ++i;
        }
        return res;
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = nums.size() - 1; i > 2; --i) {
            threeSum(nums, i, target, nums[i], res);
            while (i > 2 && nums[i - 1] == nums[i]) --i;
        }

        return res;

    }
};
