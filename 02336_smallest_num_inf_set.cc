class SmallestInfiniteSet {
    set<int> aback;
    int cur;
public:
    SmallestInfiniteSet() : cur(1) {
    }
    
    int popSmallest() {
        if (!aback.empty()) {
            auto itr = aback.begin();
            int ans = *itr;
            aback.erase(itr);
            return ans;
        }

        return cur++;
    }
    
    void addBack(int num) {
        if (num < cur && aback.find(num) == aback.end())
            aback.insert(num);
    }
};

class SmallestInfiniteSet2 {
    set<int> nums;
public:
    SmallestInfiniteSet2() {
        for (int i = 1; i < 1002; ++i)
            nums.insert(i); 
    }
    
    int popSmallest() {
        auto itr = nums.begin();
        int x = *itr;
        nums.erase(itr);
        return x;
    }
    
    void addBack(int num) {
        nums.insert(num);
    }
};


/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
