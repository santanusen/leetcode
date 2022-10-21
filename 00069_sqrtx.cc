class Solution {
public:
  int mySqrt(int x) {
    int l = 0, h = min(x, 46400);
    unsigned int m = 0;
    while (l <= h) {
      m = ((h + l) >> 1);
      uint64_t mm = m * m;
      if (mm == x)
        return m;
      if (mm > x)
        h = m - 1;
      else
        l = m + 1;
    }

    return (h + l) >> 1;
  }
};
