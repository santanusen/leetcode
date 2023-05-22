auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
vector <int> quadSearch(vector <vector<int>> &a, vector <int> &s, vector <int> &e, const vector <int> &prev) {
    vector <int> m = {(s[0] + e[0]) / 2, (s[1] + e[1]) / 2};
    
    // get Max
    int i = m[0], j = m[1];
    for (int ii = m[0], jj = s[1]; jj < e[1]; jj++)
        if (a[ii][jj] > a[i][j])
            i = ii, j = jj;
    for (int ii = s[0], jj = m[1]; ii < e[0]; ii++)
        if (a[ii][jj] > a[i][j])
            i = ii, j = jj;
    
    // test for Peak
    int cur = a[i][j];
    int up = i > 0 ? a[i - 1][j] : -1;
    int down = i < a.size() - 1 ? a[i + 1][j] : -1;
    int left = j > 0 ? a[i][j - 1] : -1;
    int right = j < a[0].size() - 1 ? a[i][j + 1] : -1;
    if (up < cur && down < cur && left < cur && right < cur) 
        return {i, j};
    
    // @Synopoly testcase check
    if (prev[0] > cur) {
        // We want to update range but 
        // it must include some Peak 
        // if cur_max < previous_max 
        // the Peak is only guaranteed if we move into a quadrant
        // that is connected to prev_max 
        i = prev[1], j = prev[2];
    }

    // range updates
    if (i < m[0] || (i == m[0] && up > cur)) e[0] = m[0];
    else s[0] = m[0] + 1;
    if (j < m[1] || (j == m[1] && left > cur)) e[1] = m[1];
    else s[1] = m[1] + 1;
    
    return quadSearch(a, s, e, {a[i][j], i, j});
}
vector<int> findPeakGrid(vector<vector<int>>& a) {
    vector <int> s = {0, 0};
    vector <int> e = {(int)a.size(), (int)a[0].size()};
    return quadSearch(a, s, e, {0, 0, 0});
}
};


class Solution2 {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = 0, h = mat.size() - 1;

        while (l <= h) {
            int m = (l + h) >> 1;
            int midx = 0, cmax = mat[m][0];
            for (int i = 1; i < mat[m].size(); ++i)
                if (mat[m][i] > cmax) {
                    cmax = mat[m][i];
                    midx = i;
                }
            if ((m == 0 || cmax > mat[m - 1][midx]) &&
                (m + 1 == mat.size() || cmax > mat[m + 1][midx]))
                return {m, midx};

            if (m > 0 && cmax < mat[m - 1][midx])
                h = m - 1;
            else
                l = m + 1;
        }

        return {-1, -1};
        
    }
};
