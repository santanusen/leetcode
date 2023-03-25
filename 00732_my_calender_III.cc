class MyCalendarThree {
    unordered_map<int, int> vals;
    unordered_map<int, int> lazy;

    void update(int start, int end, int L, int R, int idx) {
        if (start > R || end < L) return;

        if (L >= start && R <= end) { // [start [L R] end]
            ++lazy[idx];
            ++vals[idx];
            return;
        }

        int M = (L + R) / 2;
        update(start, end, L, M, idx * 2 + 1);
        update(start, end, M + 1, R, idx * 2 + 2);
        vals[idx] = lazy[idx] + max(vals[idx * 2 + 1], vals[idx * 2 + 2]);
    }

public:

    // Segment Tree
    int book(int startTime, int endTime) {
        update(startTime, endTime - 1, 1, 1E9, 0);
        return vals[0];
    }
};

class MyCalendarThree_SL {
    map<int, int> fdelta;

public:
    
    // Sweep-line algorithm
    int book(int startTime, int endTime) {
        ++fdelta[startTime];
        --fdelta[endTime];

        int olap = 0, omax = 0;
        for (auto [_, d] : fdelta) {
            olap += d;
            omax = max(omax, olap);
        }

        return omax;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
