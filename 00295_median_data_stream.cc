class MedianFinder {
    
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
public:    
    void addNum(int num) {
        if (maxq.empty() || num < maxq.top())
            maxq.push(num);
        else
            minq.push(num);
        
        if (maxq.size() > minq.size() + 1) {
            minq.push(maxq.top());
            maxq.pop();
        } else if (minq.size() > maxq.size() + 1) {
            maxq.push(minq.top());
            minq.pop();
        }
        
    }
    
    double findMedian() {
        if (maxq.size() == minq.size())
            return static_cast<double>(maxq.top() + minq.top()) / 2.0;
        else if (maxq.size() > minq.size())
            return static_cast<double>(maxq.top());
        else
            return static_cast<double>(minq.top());
    }
};
