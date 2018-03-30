//对于优化空间复杂度：1 能通过常数变量标记   2 题目自身有足够的空间
//本题属于后者，通过第一行和第一列来标记

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        if(row == 0 || col == 0)
            return;
        bool firstRowZero = false, firstColZero = false;
        for(int i = 0; i < row; i++)
            if(matrix[i][0] == 0)
                firstRowZero = true;
        for(int j = 0; j < col; j++)
            if(matrix[0][j] == 0)
                firstColZero = true;
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++)
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }
        
        for(int i = 1; i < row; i++)
            if(matrix[i][0] == 0)
                for(int j = 1; j < col; j++)
                    matrix[i][j] = 0;
        for(int j = 1; j < col; j++)
            if(matrix[0][j] == 0)
                for(int i = 1; i < row; i++)
                    matrix[i][j] = 0;
        if(firstRowZero){
            for(int i = 0; i < row; i++)
                matrix[i][0] = 0;
        }
        if(firstColZero)
            for(int j = 0; j < col; j++)
                matrix[0][j] = 0;
        
    }
};
