class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0;
        unordered_map<char, int>last_seen;
        vector<int> dist(garbage.size(), 0);
        for (int i = 1; i < garbage.size(); ++i)
            dist[i] = dist[i - 1] + travel[i - 1];

        unordered_map<char, int> units;
        for (int i = 0; i < garbage.size(); ++i) {
            units['M'] = 0;
            units['P'] = 0;
            units['G'] = 0;
            for (auto g : garbage[i]) {
                ++time;
                if (++(units[g]) == 1) {
                    time += (dist[i] - dist[last_seen[g]]);
                    last_seen[g] = i;
                }
            }
        }
        
        return time;
        
    }
};
