class SubrectangleQueries {
    vector<vector<int>>& mRect;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : mRect(rectangle) {       
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (; row1 <= row2; ++row1)
            for(int c = col1; c <= col2; ++c)
                mRect[row1][c] = newValue;
    }
    
    int getValue(int row, int col) {
        return mRect[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
