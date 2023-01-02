class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int wl = words[0].size(), cl = words.size() * words[0].size();
        if (s.size() < cl) return {};

        unordered_map<string, int> wmap;
        for (auto w : words) wmap[w]++;

        vector<int> res;
        for (int i = 0; i + cl <= s.size(); ++i) {
            // Start with wmap: Decrease frequency of each matching word.
            auto smap = wmap;
            for (int j = 0; j < words.size(); ++j) {
                auto itr = smap.find(s.substr(i + j * wl, wl));
                if (itr == smap.end()) break; // Unknown/Over-frequent word.
                if (--itr->second == 0) smap.erase(itr); // Compress smap.
            }
            if (smap.empty()) res.push_back(i); // All matched.
        }

        return res;
    }
};
