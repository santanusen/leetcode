class Solution {
public:
    int addDigits(int num) {
        //return (num == 0 ? 0 : (num % 9 ? num % 9 : 9));
        //return num == 0 ? 0 : 1 + (num - 1) % 9;
        return 1 + (num - 1) % 9;
    }
};
