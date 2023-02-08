class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        if (N < 2) return;
        const int lmax = N / 2;
        for (int l = 0; l < lmax; ++l) {
            const int dmax = N - l - 1;
            for (int d = l; d < dmax; ++d) {
                //     l,d
                //           d,-l
                //  -d,l
                //       -l,-d
                const int lb = N - 1 - l, db = N - 1 - d;
                int tmp = matrix[db][l];
                matrix[db][l] = matrix[lb][db];
                matrix[lb][db] = matrix[d][lb];
                matrix[d][lb] = matrix[l][d];
                matrix[l][d] = tmp;
            }
        }
    }
};
