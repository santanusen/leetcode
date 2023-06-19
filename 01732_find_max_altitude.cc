class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0, amax = 0;
        for (auto g : gain)
            amax = max(amax, alt = alt + g);
        return amax;
    }
};
