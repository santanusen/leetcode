class Solution {
public:
    double average(vector<int>& salary) {
        int total = 0, smin = INT_MAX, smax = INT_MIN;
        for (auto s : salary) {
            total += s;
            smin = min(smin, s);
            smax = max(smax, s);
        }

        return static_cast<double>(total - smin - smax) / (salary.size() - 2);
        
    }
};
