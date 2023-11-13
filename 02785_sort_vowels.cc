class Solution {
    int vowel_idx(char ch) {
        switch (ch) {
            case 'A': return 0;
            case 'E': return 1;
            case 'I': return 2;
            case 'O': return 3;
            case 'U': return 4;

            case 'a': return 5;
            case 'e': return 6;
            case 'i': return 7;
            case 'o': return 8;
            case 'u': return 9;

            default: break;
        }
        return -1;
    }

int nxt_vowel(int* frq, int i) {
    while (i < 10 && frq[i] < 1)
        ++i;
    return i;
}

public:
    string sortVowels(string s) {
        int frq[10] = {0};

        int i;
        for (auto ch : s)
            if ((i = vowel_idx(ch)) != -1)
                ++frq[i];

        i = nxt_vowel(frq, 0);
        const char* vowels = "AEIOUaeiou";

        for (int j = 0; j < s.size() && i < 10; ++j) {
            if (vowel_idx(s[j]) != -1) {
                --frq[i];
                s[j] = vowels[i];
                i = nxt_vowel(frq, i);
            }
        }

        return s;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
