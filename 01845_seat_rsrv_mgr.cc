class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
    int v;
public:
    SeatManager(int n) : v(1) {
    }
    
    int reserve() {
        if (pq.empty())
            return v++;

        int seatNumber = pq.top();
        pq.pop();
 
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
