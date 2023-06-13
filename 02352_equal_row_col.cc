static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct TrieNode {
    int cnt;
    unordered_map<int, TrieNode*> children;

    TrieNode() : cnt(0) {}
};

class Trie {
    TrieNode* trie;

public:
    Trie() : trie(new TrieNode) {}

    void insert(vector<int>& arr) {
        TrieNode* cur = trie;
        for (auto a : arr) {
            if (cur->children.count(a) == 0)
                cur->children[a] = new TrieNode;
            cur = cur->children[a];
        }
        ++cur->cnt;
    }

    int search(vector<vector<int>>& grid, int c) {
        TrieNode *cur = trie;
        for (int r = 0; r < grid.size(); ++r) {
            int a = grid[r][c];
            if (cur->children.count(a) == 0)
                return 0;
            cur = cur->children[a];
        }

        return cur->cnt;
    }
};

class Solution {
    string r2s(vector<int>& row) {
        string s;
        for (auto i : row)
            s += (to_string(i) + " ");
        return s;
    }

public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        Trie tr;

        for (auto& row : grid)
            tr.insert(row);

        for (int c = 0; c < n; ++c)
            ans += tr.search(grid, c);
        
        return ans;
    }

    int equalPairs3(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        unordered_map<string, int> rfreq;
        for (int r = 0; r < n; ++r)
            ++rfreq[r2s(grid[r])];

        vector<int> col(n);
        for (int c = 0; c < n; ++c) {
            for (int r = 0; r < n; ++r)
                col[r] = grid[r][c];
            ans += rfreq[r2s(col)];
        }

        return ans;
    }

    int equalPairs1(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        map<vector<int>, int> rfreq;
        for (int r = 0; r < n; ++r)
            ++rfreq[grid[r]];

        vector<int> col(n);
        for (int c = 0; c < n; ++c) {
            for (int r = 0; r < n; ++r)
                col[r] = grid[r][c];
            ans += rfreq[col];
        }

        return ans;
    }

    int equalPairs2(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                int i = 0;
                while (i < n && grid[r][i] == grid[i][c])
                    ++i;
                if (i == n)
                    ++ans;
            }
        }
        return ans;
    }
};
