class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        char res[word1.size() + word2.size() + 1];
        int N = min(word1.size(), word2.size());
        int k = 0;
        for (int i = 0; i < N; ++i) {
            res[k++] = word1[i];
            res[k++] = word2[i];
        }
        for (int i = N; i < word1.size(); ++i)
            res[k++] = word1[i];
        for (int i = N; i < word2.size(); ++i)
            res[k++] = word2[i];
            
        res[k] = '\0';

        return res;
    }
};
