class Solution {
public:
    bool detectCapitalUse(string word) {
        int uc = 0;
        for (auto c : word) if (isupper(c)) ++uc;
        return uc == 0 || uc == word.size() || (uc == 1 && isupper(word[0]));
    }

    bool detectCapitalUse2(string word) {
        for (int i = 1; i < word.size(); ++i)
            if ((isupper(word[i]) && !isupper(word[i - 1])) ||
                (!isupper(word[i]) && isupper(word[i - 1]) && i > 1))
                return false;
        return true;
    }
};
