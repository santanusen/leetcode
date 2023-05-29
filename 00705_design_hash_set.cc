static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class MyHashSet {
    vector<bool> s;
public:
    MyHashSet() : s(1E6 + 1, false) {}

    void add(int key) { s[key] = true; }
    
    void remove(int key) { s[key] = false; }
    
    bool contains(int key) { return s[key]; }
};

/*
class MyHashSet2 {
    unordered_set<int> s;
public:

    void add(int key) {
        s.insert(key);        
    }
    
    void remove(int key) {
        s.erase(key);
    }
    
    bool contains(int key) {
        return s.find(key) != s.end();
    }
};
*/

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
