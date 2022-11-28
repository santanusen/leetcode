class Solution {
    /*
        diff from cycle start - diagonal chars diff from cycle start in brackets().
13579 = 2
24680 = 2
    
1 5 9 3 = 4 
246802  = (2) 4
3 7 1   = 4
    
    
1  7  3 = 6
2 68 24 = (4) 6 (4) 6
35 91 5 = (2) 6 (2) 6
4  0  6 = 6
    
    
1   9   7 = 8
2  80  68 = (6) 8 (6) =>  2 * (nr - 1 - row)  
3 7 1 5 9 = (4) 8 (4)
46  24  0 = (2) 8 (2)
5   3   1

diagonal character ofset =
row + cycle + 2 * (nr - 1 - row) = cycle - row + 2 * (nr - 1) =
cycle + cl - row

*/
    
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int n = s.size();
        string ret (n, '\0'); int p = 0;
        
        int clen = 2 * (numRows - 1); // Cycle length
        for (int row = 0; row < numRows; ++row)
            for (int cycl = 0; cycl + row < n; cycl += clen) {
                ret[p++] = s[cycl + row]; // Columnar characters
                // Inner rows have one extra diagonal chracter per cycle
                if (row != 0 && row != numRows - 1 && cycl + clen - row < n)
                    ret[p++] = s[cycl + clen - row];
            }
        return ret;
    }
};



