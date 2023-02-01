class SummaryRanges {
    map<int, int> ranges; // Treemap: ranges[rangeStart] = rangeEnd;
public:    
    void addNum(int value) {

        if (ranges.empty()) { // Base case
            ranges[value] = value;
            return;
        }

        auto ge = ranges.lower_bound(value); // Closest range with start >= value. 
        if (ge == ranges.end()) { // No range with start greater than or equals. ranges = {[1,3][6,7]} value = 8
            auto last = ranges.rbegin();
            if (value == last->second + 1) // Merge with the last range. {[1,3][6,7]} + 8 = {[1,3][6,8]}
                last->second = value;
            else if (value > last->second) // Can't merge. {[6,7]} + 10 = {[6,7][10,10]}
                ranges[value] = value;

        } else { // We have a range starting with >= value
            if (ge->first == value) return; // {[4,7]} + 4

            auto lt = ranges.end(); // Closest range starting with < value
            if (ge != ranges.begin()) { // {[1,3][7,8]} + 4 : ge = [7,8] lt = [1,3] 
                lt = ge;                // {[7,8]} + 2 : ge = [7,8] lt = none
                --lt;
            }
            auto cur = lt; // Current range where value will be added
            if (lt == ranges.end() || lt->second < value - 1) { // {[3,6]} + 1 or {[1,2][9,10]} + 5
                cur = ranges.insert({value, value}).first;
            } else if (value == lt->second + 1) { // Extend lt: {[4,5][9,10]} + 6
                lt->second = value;
            } else if (value <= lt->second) { // Repeated value: {[4,6][9,10]} + 5
                return;
            }

            if (cur->second + 1 == ge->first) { // Merge current with next: {[1,2][4,5]} + 3 = {[1,3][4,5]} = {[1,5]}
                cur->second = ge->second;
                ranges.erase(ge);
            }
        }
        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& r: ranges)
            res.push_back({r.first, r.second});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
