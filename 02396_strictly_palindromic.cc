class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        
        for (int b = 2; b <= n - 2; ++b) {
            // Can't be a palindrome with trailing 0's
            if (n != 0 && n % b == 0)
                return false;
            
            int nr = 0, nf = n; // Reverse and forward numbers.
            while (nr < nf) { // Till half or more digits transferred from forward to reverse number.
                nr = (nr * b) + (nf % b);
                nf /= b;
            }
            
            if (nf != nr && nf != nr / b) // Even or odd length palindrome
                return false;
        }
        
        return true;
        
    }
};
