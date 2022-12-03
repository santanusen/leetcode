class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> freq;
        for (auto n : arr)
            ++freq[n];
        
        unordered_set<int> freqset;
        for (auto& p : freq)
            if (!freqset.insert(p.second).second)
                return false;
        
        return true;
    }
};
