class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n,m;
        int row, column;
        
        n = matrix.size();
        m = matrix[0].size();
        row = n-1; column = m-1;
        while(row>0 && matrix[row-1][column]>=target) row--;
        while(column>0 && matrix[row][column-1]>=target) column--;
        if(matrix[row][column]==target) return 1; else return 0;
        
    }
};
