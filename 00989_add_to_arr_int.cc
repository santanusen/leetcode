class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int carry = 0, i = num.size() - 1;
        while (carry || i > -1 || k) {
            int sum = carry;
            sum += (k % 10);
            k /= 10;
            if (i > -1) sum += num[i--];
            res.push_back(sum % 10);
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
        
    }

    vector<int> addToArrayForm2(vector<int>& num, int k) {
        vector<int> res(max(num.size(), to_string(k).length()) + 1);
        res[0] = 0;
        int carry = 0, i = num.size() - 1, j = res.size() - 1;
        while (carry || i > -1 || k) {
            int sum = carry;
            sum += (k % 10);
            k /= 10;
            if (i > -1) sum += num[i--];
            res[j--] = sum % 10;
            carry = sum / 10;
        }

        // return (res[0] == 0) ? vector<int>(res.begin() + 1, res.end()) : res;
        if (res[0] == 0) res.erase(res.begin());
        return res;
        
    }
};
