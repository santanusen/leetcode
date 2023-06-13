class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto itr = upper_bound(letters.begin(), letters.end(), target);
        return (itr == letters.end()) ? letters[0] : *itr;
    }

    char nextGreatestLetter1(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (letters[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }

        return l == letters.size() ? letters[0] : letters[l];
        
    }

    char nextGreatestLetter2(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (letters[m] <= target)
                l = m + 1;
            else {
                if (m == 0 || letters[m - 1] <= target)
                    return letters[m];
                else
                    r = m - 1;
            }
        }

        return letters[0];
        
    }
};
