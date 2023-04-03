class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        for (int i = 0; i < spells.size(); ++i) {
            long long sp = spells[i];
            int l = 0, r = potions.size() - 1;
            if (sp * potions[l] >= success) {
                spells[i] = potions.size();
                continue;
            }
            if (sp * potions[r] < success) {
                spells[i] = 0;
                continue;
            }
            while (l <= r) {
                int m = (l + r) / 2;
                if (sp * potions[m] < success)
                    l = m + 1;
                else
                    r = m - 1;
            }

            spells[i] = potions.size() - l;
        }

        return spells;
        
    }
};
