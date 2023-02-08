class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left, right;
        unordered_map<int, int> basket;
        // Sliding window of 2 elements.
        for (right = 0; right < fruits.size(); ++right) {
            ++basket[fruits[right]];
            if (basket.size() > 2) {
                if (--basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                ++left;
            }
        }
        // Once window reaches max size, it just keeps shifting; does not shrink.
        return right - left;
    }

    int totalFruit2(vector<int>& fruits) {
        vector<int> dp(fruits.size());
        dp[0] = 1;
        for (int i = 1; i < fruits.size(); ++i)
            dp[i] = (fruits[i] == fruits[i - 1]) ? dp[i - 1] + 1 : 1;

        int res = 0;
        int pos = dp.size() - 1;
        while (pos > -1) {
            unordered_set<int> ff {fruits[pos]};
            int ppos = pos, cres = 0;
            while (ff.size() < 3 && pos > -1) {
                ppos = pos;
                cres += dp[pos];
                pos -= dp[pos];
                if (pos > -1) ff.insert(fruits[pos]);
            }
            res = max(res, cres);
            if (pos > 0) pos = ppos;
        }
        return res;
    }
};
