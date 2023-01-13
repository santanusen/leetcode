class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        for (auto t : tasks) ++freq[t];

        int trips = 0;
        for (auto [t, f] : freq)
            if (f == 1) return -1;
            else trips += ((f + 2) / 3);
        return trips;
    }
};
