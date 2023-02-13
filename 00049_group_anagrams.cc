//#include <boost/functional/hash.hpp>
class Solution {
    template<typename T>
    struct ContainerHash {
        int operator()(const T& v) const {
            unsigned int hash = v.size();
            for (auto& i : v)
                hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            return hash;
            //return boost::hash_range(v.begin(), v.end());
        }
    };
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> tbl;
        for (auto& s : strs) {
            vector<int> frq(26, 0);
            for (auto c : s) ++frq[c - 'a'];
            string fs;
            for (int i = 0; i < 26; ++i)
                if (frq[i])
                    fs.append(frq[i], i + 'a');
            tbl[fs].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& p: tbl) {
            res.push_back({});
            res.back().swap(p.second);
        }
        return res;
    }

    vector<vector<string>> groupAnagrams4(vector<string>& strs) {
        unordered_map<string, vector<string>> tbl;
        for (auto& s : strs) {
            string ss = s;
            sort(ss.begin(), ss.end());
            tbl[ss].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& p: tbl) {
            res.push_back({});
            res.back().swap(p.second);
        }
        return res;
    }

    vector<vector<string>> groupAnagrams3(vector<string>& strs) {
        unordered_map<string, vector<string>> tbl;
        for (auto& s : strs) {
            vector<int> frq(26, 0);
            for (auto c : s) ++frq[c - 'a'];
            string fs;
            for (int i = 0; i < 26; ++i)
                if (frq[i])
                    fs += to_string(frq[i]) + char(i + 'a');
            tbl[fs].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& p: tbl) {
            res.push_back({});
            res.back().swap(p.second);
        }
        return res;
    }

    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, ContainerHash<vector<int>>> tbl;
        for (auto& s : strs) {
            vector<int> frq(26, 0);
            for (auto c : s) ++frq[c - 'a'];
            tbl[frq].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& p: tbl) {
            res.push_back({});
            res.back().swap(p.second);
        }
        return res;
    }
};
