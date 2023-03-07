class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end(), greater<int>());
        int score = 0, incr = 0;
        for (auto s : sat) {
            incr += s;
            if (incr < 0) break;
            score += incr;
        }

        return score;      
    }
};
