int _ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return 0;
} ();

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int kk;
public:
    KthLargest(int k, vector<int>& nums) : kk(k) {
        for (const auto& n : nums) add(n);
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > kk) pq.pop();
        
        return pq.top();
    }

/*
    int add2(int val) {
        if (pq.size() < kk)
            pq.push(val);
        else if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
*/
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
