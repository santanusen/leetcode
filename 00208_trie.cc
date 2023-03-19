class Trie {
    struct TrieNode {
        bool isWord;
        TrieNode* child[26];
        TrieNode() : isWord(false), child {NULL} {}
    } *mDict;
public:
    Trie() : mDict(new TrieNode) {}
    
    void insert(string word) {
        TrieNode* tr = mDict;
        for (auto ch : word)
            tr =  tr->child[ch - 'a'] = (tr->child[ch - 'a']) ? tr->child[ch - 'a'] : new TrieNode;
        tr->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* tr = mDict;
        for (auto ch : word)
            if (!(tr = tr->child[ch - 'a']))
                return false;      
        return tr->isWord;     
    }
    
    bool startsWith(string prefix) {
        TrieNode* tr = mDict;
        for (auto ch : prefix)
            if (!(tr = tr->child[ch - 'a']))
                return false;
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
