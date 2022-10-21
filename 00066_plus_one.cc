class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for (int i = digits.size() - 1; i > -1 && c != 0; --i) {
            digits[i] += c;
            c = digits[i] / 10;
            digits[i] %= 10;
        }

        if (c) {
            digits.push_back(0);
            digits[0] = c;
            //digits.insert(digits.begin(), c);
        }

        return digits;
    }
};
