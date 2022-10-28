class Solution {
public:
    // Solution 1 : Brute Force
    int largestOverlap2(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int n = img1.size();
        int max_ol = 0;
        
        for (int r1 = 0; r1 < n; ++r1) {
            int nr1 = n - r1;
            if (nr1 * n <= max_ol)
                break;
            for (int c1 = 0; c1 < n; ++c1) {
                int nc1 = n - c1;
                if (nr1 * nc1 <= max_ol)
                    break;
                
                for (int r2 = 0; r2 < n; ++r2) {
                    int nr2 = min(nr1, n - r2);
                    if (nr2 * nc1 <= max_ol)
                        break;
                    
                    for (int c2 = 0; c2 < n; ++c2) {
                        int nc2 = min(nc1, n - c2); 
                        if (nr2 * nc2 <= max_ol)
                            break;
                        
                        int ol = 0;
                        for (int x = 0; x < nr2; ++x) {
                            int nx = nr2 - x;
                            if (ol + nx * nc2 <= max_ol)
                                break;
                            for (int y = 0; y < nc2; ++y) {
                                if (img1[r1 + x][c1 + y] == 1 && img2[r2 + x][c2 + y] == 1)
                                    ++ol;
                            }
                        }
                        max_ol = max(ol, max_ol);
                    }
                }
            }
        }
        
        return max_ol;
    }

    
    // Solution 2 : Window Shift
    int shiftAndCount(int dx, int dy, vector<vector<int>>& M, vector<vector<int>>& R) {
        int lcount = 0, rcount = 0;
        
        for (int mr = dy, rr = 0; mr < M.size(); ++mr, ++rr){
            for (int mc = dx, rc = 0; mc < M.size(); ++mc, ++rc) {
                lcount += (M[mr][mc] & R[rr][rc]);
                rcount += (M[mr][rc] & R[rr][mc]);
            }
        }
        
        return max(lcount, rcount);
    }
    
    int largestOverlap3(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int max_ol = 0;
        for (int dy = 0; dy < img1.size(); ++dy)
            for (int dx = 0; dx < img1.size(); ++dx) {
                max_ol = max(max_ol, shiftAndCount(dx, dy, img1, img2));
                max_ol = max(max_ol, shiftAndCount(dx, dy, img2, img1));
            }
        
        return max_ol;
    }
    
    // Solution 3 : Linear Transformation
    void non_zero_cells(vector<vector<int>>& M, vector<pair<int, int>>& ret) {
        for (int r = 0; r < M.size(); ++r)
            for (int c = 0; c < M.size(); ++c)
                if (M[r][c])
                    ret.push_back(make_pair(r, c));
    }
    
    struct hash_pair {
        size_t operator()(const pair<int, int>& p) const {
            return std::hash<int>{}(((100 + p.first) << 16) | (100 + p.second));
        }
    };
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> o1, o2;
        non_zero_cells(img1, o1);
        non_zero_cells(img2, o2);
        
        int max_ol = 0;
        unordered_map<pair<int, int>, int, hash_pair> gc;
        for (auto& a : o1) {
            for (auto& b : o2) {
                auto v = make_pair(a.first - b.first, a.second - b.second);
                max_ol = max((++gc[v]), max_ol);
            }
        }
        
        return max_ol;
    }
    
};
