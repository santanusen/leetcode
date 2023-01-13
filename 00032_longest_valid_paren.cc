class Solution {
public:
    int longestValidParentheses(string s) {
        // DP: Longest match till index.
        vector<int> dp(s.size() + 1);
        dp[0] = 0;

        int longest = 0;
        for (int i = 1, lp = 0; i < dp.size(); ++i) {
            if (s[i - 1] == '(')
                ++lp;
            else if (lp > 0) {
                --lp; // Matched a left paranthesis.
                dp[i] = dp[i - 1] + 2; // That increases the match length by 2 : (()) -> 0024
                dp[i] += dp[i - dp[i]]; // Does this completion append to a previous streak? ()() ->0204
                longest = max(longest, dp[i]);
            }
        }

        return longest;
    }

    int longestValidParentheses2(string s) {

        // Indexes that had a matching parenthesis.
        vector<bool> matched(s.size() + 1, false);

        // Check which indexes have a match.
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                stk.push(i);
            else if (!stk.empty()) {
                matched[i] = matched[stk.top()] = true;
                stk.pop();
            }
        }

        // Find the longest sequence of indexes that has match.
        int longest = 0, cur = 0;
        for (auto m : matched) {
            if (m)
                ++cur;
            else {
                longest = max(longest, cur);
                cur = 0;
            }
        }

        return longest;
        
    }
};
