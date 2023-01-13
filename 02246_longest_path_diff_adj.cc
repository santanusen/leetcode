class Solution {
    int maxlen;

    int dfs(int cur, vector<vector<int>>& children, const string& s) {
        int l1 = 0, l2 = 0;
        for (auto ch : children[cur]) {
            auto cl = dfs(ch, children, s);
            if (s[cur] != s[ch] && cl > l2) {
                l2 = cl;
                if (l2 > l1) swap(l1, l2);
            }
        }
        maxlen = max(maxlen, l1 + l2 + 1);
        return 1 + l1;
    }

public:
    int longestPath(vector<int>& parent, string s) {
        maxlen = 0;
        vector<vector<int>> children(parent.size());
        for (int i = 1; i < parent.size(); ++i)
            children[parent[i]].push_back(i);

        dfs(0, children, s);
        return maxlen;        
    }
};
