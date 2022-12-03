class Solution {
public:
    string frequencySort(string s) {
        constexpr int N = 'z' - '0' + 1;
        int freq[N] = {0};
        for (auto c : s)
            ++freq[c - '0'];
        
        multimap<int, char, greater<int>> fmap;
        for (int i = 0; i < N; ++i)
            if (freq[i])
                fmap.insert({freq[i], '0' + i});
        
        string res;
        for (auto& p : fmap)
            res.insert(res.end(), p.first, p.second);
        
        return res;
        
    }
};
