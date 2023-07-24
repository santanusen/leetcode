#if 1
#define TEN_COPY(...) __VA_ARGS__, __VA_ARGS__, __VA_ARGS__, __VA_ARGS__, __VA_ARGS__, \
                      __VA_ARGS__, __VA_ARGS__, __VA_ARGS__, __VA_ARGS__, __VA_ARGS__
#define HUNDRED_COPY(...) TEN_COPY(TEN_COPY(__VA_ARGS__))
#define TEN_THOUSAND_COPY(x) HUNDRED_COPY(HUNDRED_COPY(x))

#define LRUCache_NONE 10001
#define LRUCache_NO_KEY_VAL -1

class LRUCache
{
  public:
    int M[10001] = { TEN_THOUSAND_COPY(LRUCache_NO_KEY_VAL), LRUCache_NO_KEY_VAL };
    inline static int16_t L[10002][2];
    int cap, size = 0;
    const int NONE = 10001;
    int head = NONE, tail = NONE;
    LRUCache(int capacity) : cap(capacity) { /*memset(M, 0xff, sizeof M);*/ }
    inline void erase(int key)
    {
        const int pre = L[key][0];
        const int nxt = L[key][1];
        L[pre][1] = nxt;
        L[nxt][0] = pre;
        if (head == key) head = nxt;
        if (tail == key) tail = pre;
    }
    inline void push_front(int key)
    {
        L[key][0] = NONE;
        L[key][1] = head;
        L[head][0] = key;
        head = key;
        if (tail == NONE) tail = key;
    }
    inline int pop_back()
    {
        int ret = tail;
        tail = L[tail][0];
        L[tail][1] = NONE;
        if (tail == NONE) head = NONE;
        return ret;
    }
    int get(int key)
    {
        if (M[key] == -1) return -1;
        erase(key);
        push_front(key);
        return M[key];
    }
    void put(int key, int value)
    {
        if (M[key] != -1) erase(key);
        else
        {
            if (size == cap)
            {
                int poped = pop_back();
                M[poped] = -1;
                size -= 1;
            }
            size += 1;
        }
        push_front(key);
        M[key] = value;
    }
};

#else
class LRUCache {
    int cap;
    list<int> hist;
    unordered_map<int, pair<int, list<int>::iterator>> kv;

    void refresh(unordered_map<int, pair<int, list<int>::iterator>>::iterator kitr) {
        hist.erase(kitr->second.second);
        hist.push_front(kitr->first);
        kitr->second.second = hist.begin();
    }

public:
    LRUCache(int capacity) : cap(capacity) {
    }
    
    int get(int key) {
        auto kitr = kv.find(key);
        if (kitr == kv.end())
            return -1;
        refresh(kitr);
        return kitr->second.first;
    }
    
    void put(int key, int value) {
        auto kitr = kv.find(key);
        if (kitr != kv.end()) {
            kitr->second.first = value;
            refresh(kitr);
            return;
        }

        if (kv.size() == cap) {
            int ekey = *hist.rbegin();
            hist.pop_back();
            kv.erase(ekey);
        }

        hist.push_front(key);
        kv[key] = {value, hist.begin()};
    }
};
#endif

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return false;}();
