class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, level = 0, water = 0;
        while (l < r) {
            int lower = (height[l] < height[r]) ? height[l++] : height[r--];
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }

    int trap2(vector<int>& height) {
        int water = 0;
        int i = 0;
        while (i < height.size()) {
            int left = i;
            // Left boundary is at the peak of incline.
            while (left + 1 < height.size() && height[left + 1] >= height[left])
                ++left;
            if (left + 1 >= height.size())
                break;

            // Right boundary is the first block with height >= left boundary
            int right = left + 1;

            int midx = right, occupied = 0, mocc = 0;
            while (right + 1 < height.size() && height[right] < height[left]) {
                occupied += height[right];
                ++right;
                if (height[midx] < height[right]) {
                    midx = right;
                    mocc = occupied;
                }
            }

            if (height[right] < height[left]) {
                right = midx;
                occupied = mocc;
            }

            water += (min(height[left], height[right]) * (right - left - 1) - occupied);
            i = right;
        }

        return water;
        
    }
};
