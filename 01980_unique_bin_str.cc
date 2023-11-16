class Solution {
    struct DictNode {
        DictNode* child[2];
        DictNode() : child{NULL, NULL} {}
    };
    DictNode* dict;

    void dictAddStr(const string& s) {
        DictNode* cur = dict;
        for (auto c : s) {
            int ci = c - '0';
            if (!cur->child[ci])
                cur->child[ci] = new DictNode;
            cur = cur->child[ci];
        }
    }

    string dfs(char* s, int pos, int n, DictNode* cur) {
        if (pos == n) {
            return ((cur) ? "" : string(s, s + n));
        }

        if (!cur) {
            string ans(s, s + pos);
            ans.append(n - pos, '0');
            return ans;
        }

        for (int ci = 0; ci < 2; ++ci) {
            s[pos] = '0' + ci;
            string ans = dfs(s, pos + 1, n, cur->child[ci]);
            if (!ans.empty())
                return ans;
        }

        return "";
    }

public:

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        char str[17] = {0};

        for(int i = 0; i < n; ++i)
          str[i] = (nums[i][i] == '0' ? '1' : '0');

        return str;
    }

    string findDifferentBinaryString2(vector<string>& nums) {
        dict = new DictNode;
        for (auto& s : nums)
            dictAddStr(s);

        char s[nums[0].size()];
        return dfs(s, 0, nums[0].size(), dict);
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
