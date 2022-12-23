class Solution {
public:
    string intToRoman(int num) {
        string res;
        int si = 0;
        const string sym = "IVXLCDM";
        while (num) {
            int m = num % 10;
            if (m == 9)
                res = string(1, sym[si]) + sym[si + 2] + res;
            else if (m > 4)
                res = string(1, sym[si + 1]) + string(m - 5, sym[si]) + res;
            else if (m == 4)
                res = string(1, sym[si]) + sym[si + 1] + res;
            else
                res = string(m, sym[si]) + res;
            
            si += 2;
            num /= 10;
        }

        return res;
    }
}
