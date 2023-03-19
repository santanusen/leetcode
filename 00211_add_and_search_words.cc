class WordDictionary {
    struct TrieNode {
        bool isWord;
        TrieNode* child[26];

        TrieNode() : isWord(false), child{NULL} {}
    } *dict;

    bool dfs(const string& word, int pos, TrieNode* cur) {
        if (pos == word.size()) return cur->isWord;

        for (; pos < word.size(); ++pos) {
            auto ch = word[pos];
            if (ch == '.') {
                for (auto chld : cur->child)
                    if (chld && dfs(word, pos + 1, chld))
                        return true;
                return false;
            }
            cur = cur->child[ch - 'a'];
            if (!cur) return false;
        }

        return cur->isWord;
    }

public:
    WordDictionary() : dict(new TrieNode) {
    }
    
    void addWord(string word) {
        auto cur = dict;
        for (auto ch : word)
            cur = cur->child[ch - 'a'] = (cur->child[ch - 'a']) ? cur->child[ch - 'a'] : new TrieNode;
        cur->isWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, dict);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
