class BrowserHistory {
    vector<string> urls;
    int cur;
    int last;
public:
    BrowserHistory(string homepage) : urls{homepage}, cur(0), last(0) {
    }
    
    void visit(string url) {
        last = ++cur;
        if (cur == urls.size())
            urls.push_back(url);
        else
            urls[cur] = url;
    }
    
    string back(int steps) {
        cur = max(0, cur - steps);
        return urls[cur];
    }
    
    string forward(int steps) {
        cur = min(cur + steps, last);
        return urls[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
