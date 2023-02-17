class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tbal = 0, s = 0;
        for (int i = 0, cbal = 0; i < gas.size(); ++i) {
            tbal += (gas[i] - cost[i]);
            if ((cbal += (gas[i] - cost[i])) < 0) {
                s = i + 1;
                cbal = 0;
            }
        }
        return (tbal < 0 ? -1: s);
    }
};
