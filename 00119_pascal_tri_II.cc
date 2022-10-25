class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        for (int r = 0; r <= rowIndex; ++r)
            for (int c = r - 1; c > 0; --c)
                row[c] += row[c - 1];
        return row;
    }
};
