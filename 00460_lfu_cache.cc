class LFUCache {
    int cap;
    int minf;
    unordered_map<int, int> kv; // key : value
    unordered_map<int, list<int>> freq; // freq : list<key>
    unordered_map<int, pair<int, list<int>::iterator>> lookup; // key : frequency, entry

    void prune() {
        if (kv.empty()) return;
        // Remove from freq
        auto itr = freq.find(minf);
        auto frq = itr->first;
        auto key = itr->second.back();
        itr->second.pop_back();
        if (itr->second.empty()) freq.erase(itr);

        // Remove from kv and lookup
        kv.erase(key);
        lookup.erase(key);
    }

    void incr_freq(int key) {
        auto itr = lookup.find(key);
        int frq = 1;
        if (itr != lookup.end()) { // Existing key
            frq = itr->second.first;
            auto fitr = freq.find(frq);
            fitr->second.erase(itr->second.second);
            if (fitr->second.empty()) {
                freq.erase(fitr);
                if (frq == minf) ++minf;
            } 
            ++frq;
        } else {
            minf = 1;
        }
        
        auto& fl = freq[frq];
        fl.push_front(key);
        lookup[key] = {frq, fl.begin()};
    }

public:
    LFUCache(int capacity) : cap(capacity), minf(0) {}
    
    int get(int key) {
        auto itr = kv.find(key);
        if (itr == kv.end()) return -1;

        incr_freq(key);
        return itr->second;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        if (kv.find(key) == kv.end() && kv.size() == cap)
            prune();
        kv[key] = value;
        incr_freq(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


class LFUCache2 {
    // key: frequency, value: list of original key-value pairs that have the same frequency.
    unordered_map<int, list<pair<int, int>>> frequencies;
    // key: original key, value: pair of frequency and the iterator corresponding key int the
    // frequencies map's list.
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
    int capacity;
    int minf;

    void insert(int key, int frequency, int value) {
        frequencies[frequency].push_back({key, value});
        cache[key] = {frequency, --frequencies[frequency].end()};
    }

public:
    LFUCache(int capacity) : capacity(capacity), minf(0) {}

    int get(int key) {
        const auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        const int f = it->second.first;
        const auto iter = it->second.second;
        const pair<int, int> kv = *iter;
        frequencies[f].erase(iter);
        if (frequencies[f].empty() && minf == f) {
            ++minf;
        }
        insert(key, f + 1, kv.second);
        return kv.second;
    }

    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        const auto it = cache.find(key);
        if (it != cache.end()) {
            it->second.second->second = value;
            get(key);
            return;
        }
        if (capacity == cache.size()) {
            cache.erase(frequencies[minf].front().first);
            frequencies[minf].pop_front();
        }
        minf = 1;
        insert(key, 1, value);
    }
};

