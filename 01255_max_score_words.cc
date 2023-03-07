class Solution {
    int dfs(vector<string>& words, int pos, vector<int>& lavail, vector<int>& score) {
        if (pos >= words.size()) return 0;
        // Score without including current word
        int s1 = dfs(words, pos + 1, lavail, score);

        // Score including (if possible) current word
        int s2 = 0;
        vector<int> lavail2 = lavail;
        for (auto c : words[pos]) {
            if (--lavail2[c - 'a'] < 0)
                return s1;
            s2 += score[c - 'a'];
        }
        s2 += dfs(words, pos + 1, lavail2, score);
        return max(s1, s2);
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> lavail(26, 0);
        for (auto c : letters)
            ++lavail[c - 'a'];
        return dfs(words, 0, lavail, score);    
    }
};
