class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        
        int xr = 0;
        while (x > xr) {
            xr = 10 * xr + (x % 10);
            x /= 10;
        }
        
        return (x == xr || x == xr / 10);
        
    }
};
