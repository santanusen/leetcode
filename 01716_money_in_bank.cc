class Solution {
public:
    int totalMoney(int n) {
        int wbase = 28; // 7 * 8 / 2
        int nweeks = n / 7;
        int moneyw = (wbase * nweeks) + 7 * (nweeks * (nweeks - 1)) / 2;
        int ndays = n % 7;
        int moneyd = (ndays * (ndays + 1)) / 2 + ndays * nweeks;

        return moneyw + moneyd;
    }
};
