/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    stack<pair<vector<NestedInteger>*, int>> stk;

    bool isCurInt() {
        if (stk.empty())
            return false;
        auto [pNI, pos] = stk.top();
        if (pos < (*pNI).size())
            return (*pNI)[pos].isInteger();

        return false;
    }

    bool isCurDone() {
        if (stk.empty())
            return false;

        auto [pNI, pos] = stk.top();
        return pos >= (*pNI).size();   
    }

    void moveToNextInt() {
        if (stk.empty())
            return;

         do {
            auto [pNI, pos] = stk.top();
            stk.pop();
            stk.push({pNI, pos + 1});
            if (isCurDone())
                stk.pop();
            else
                if (!isCurInt())
                    stk.push({&(*stk.top().first)[stk.top().second].getList(), -1});
        } while (!(stk.empty() || isCurInt()));
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.push({&nestedList, -1});
        moveToNextInt();
    }
    
    int next() {
        if (stk.empty())
            return -1;

        auto [pNI, pos] = stk.top();
        int ans = (*pNI)[pos].getInteger();
        moveToNextInt();
        return ans;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
