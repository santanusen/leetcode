struct DictNode {
    bool isWord;
    DictNode* child[26];

    DictNode() : isWord(false), child {0} {
    }
};

void dictAdd(DictNode* dict, const string& word) {
    for (auto c : word) {
        int pos = c - 'a';
        if (!dict->child[pos])
            dict->child[pos] = new DictNode;
        dict = dict->child[pos];
    }

    dict->isWord = true;
}

class Solution {
    uint8_t dfs(const string& s, DictNode* dict, int spos, int pos, DictNode* parent,
             vector<int8_t>& memo) {
        if (pos == s.size())
            return parent->isWord ? 1 : 0;

        if (memo[spos] != -1)
            return memo[spos];

        DictNode* cur = parent->child[s[pos] - 'a'];
        if (!cur)
            return memo[spos] = 0;

        if (cur->isWord && dfs(s, dict, pos + 1, pos + 1, dict, memo))
            return memo[spos] = 1;

        return memo[spos] = dfs(s, dict, spos, pos + 1, cur, memo);

    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        DictNode dict;
        for (auto& word : wordDict)
            dictAdd(&dict, word);

        vector<int8_t> memo(s.size(), -1);
        
        return dfs(s, &dict, 0, 0, &dict, memo);
    }
};


class Solution2 {
    uint8_t dfs(const string& s, DictNode* dict, int spos, int pos, DictNode* parent,
             vector<vector<int8_t>>& memo) {
        if (pos == s.size())
            return parent->isWord ? 1 : 0;

        if (memo[spos][pos] != -1)
            return memo[spos][pos];

        DictNode* cur = parent->child[s[pos] - 'a'];
        if (!cur)
            return memo[spos][pos] = 0;

        if (cur->isWord && dfs(s, dict, pos + 1, pos + 1, dict, memo))
            return memo[spos][pos] = 1;

        return memo[spos][pos] = dfs(s, dict, spos, pos + 1, cur, memo);

    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        DictNode dict;
        for (auto& word : wordDict)
            dictAdd(&dict, word);

        vector memo(s.size(), vector<int8_t>(s.size(), -1));
        
        return dfs(s, &dict, 0, 0, &dict, memo);
    }
};
