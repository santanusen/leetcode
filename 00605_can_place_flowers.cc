class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int slots[2] = {0, 0};
        for (int i = 0, s = 0; i < flowerbed.size(); ++i, s = i % 2) {
            if (flowerbed[i] == 0 && (i < 1 || flowerbed[i - 1] == 0) &&
                (i + 1 >= flowerbed.size() || flowerbed[i + 1] == 0))
                if (++slots[s] >= n) return true;
        }

        return false;
        
    }
};
