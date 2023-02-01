class Solution {
    /* DFS :
       Return true if there exists an i such that str[pos : i] is present in the
       primes dictionary and dfs(str, i + 1) is also true.
       min_pl is the length of the shortest non-empty prime string.
    */
    bool dfs(unordered_set<string>& primes, int min_pl, const string& str, int pos) {
        if (pos == str.length()) return true; // Base case
        for (int len = min_pl; pos + len <= str.length(); ++len) {
            if (primes.count(str.substr(pos, len)) && dfs(primes, min_pl, str, pos + len))
                return true;
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // Sort the words according to their lengths.
        sort(words.begin(), words.end(), [](const string& s1, const string& s2) {return s1.length() < s2.length();});

        // Result to be returned.
        vector<string> res;

        // Discard any empty words.
        int s = 0;
        while (words[s].empty()) ++s;
        if (s == words.size()) return res;

        // Dictionary of the "prime" words - words not decomposable into smaller words.
        // Start with the smallest sized, non-empty word in the prime dictionary.
        unordered_set<string> primes {words[s]};

        // Go over the rest of the words.
        for (int i = 1 + s; i < words.size(); ++i) {
            // Words with same length as the smallest prime cannot be decomposed.
            if (words[i].length() == words[s].length()) {
                primes.insert(words[i]);
                continue;
            }
            // Non primes make it to the result, primes to the dictionary.
            if (dfs(primes, words[s].length(), words[i], 0))
                res.push_back(words[i]);
            else
                primes.insert(words[i]);
        }
        return res;
    }
};
