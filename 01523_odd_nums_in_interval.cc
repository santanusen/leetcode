class Solution {
public:
    int countOdds(int low, int high) {
        /*
        // Both low and high are even
        if (((low | high) & 0x1) == 0)
            return (high - low) >> 1;
        // Both low and high are odd
        if (low & high & 0x1)
            return ((high - low) >> 1) + 1;
        // One of low and high is odd
        return (high - low + 1) >> 1;
        */
        return ((high + 1) / 2) - (low / 2);
    }
};
