class MyHashMap {
    static const int MIN_BUCKETS = 128;

    uint32_t A;
    uint32_t B;
    int nelem;
    vector<list<pair<int, int>>> buckets;

    void hash_reinit () {
        int N = buckets.size();
        while ((A = rand() % N) < 4)
            ;
        while ((B = rand() % N) < 4)
            ;
    }

    int hash (uint32_t key) const {
        return ((A + B * key) % buckets.size());
    }

    void rehash(int sz) {
        vector<list<pair<int, int>>> old_buckets(sz);
        buckets.swap(old_buckets);
        hash_reinit();
        for (auto& lst : old_buckets)
            for (auto [k, v] : lst)
                buckets[hash(k)].push_back({k, v});
    }

    list<pair<int, int>>::iterator search(list<pair<int, int>>& lst, int key) {
        auto itr = lst.begin();
        while (itr != lst.end()) {
            if (itr->first == key)
                break;
            ++itr;
        }

        return itr;
    }
 
public:
    MyHashMap() : A(0), B(0), nelem(0), buckets(MIN_BUCKETS) {
        hash_reinit();
    }
    
    void put(int key, int value) {
        if (nelem == buckets.size())
            rehash(2 * buckets.size());

        auto h = hash(key);
        auto& buck = buckets[h];
        auto itr = search(buck, key);
        if (itr != buck.end())
            itr->second = value;
        else
            buck.push_back({key, value});
        ++nelem;
    }
    
    int get(int key) {
        auto h = hash(key);
        auto& buck = buckets[h];
        auto itr = search(buck, key);
        if (itr != buck.end())
            return itr->second;
        return -1;
    }
    
    void remove(int key) {
        auto h = hash(key);
        auto& buck = buckets[h];
        auto itr = search(buck, key);
        if (itr != buck.end())
            buck.erase(itr);
        --nelem;
        if (buckets.size() > MIN_BUCKETS && nelem <= buckets.size() / 4)
            rehash(buckets.size() / 2);
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
