class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
        int cols = array[0].size();
        int row = rows - 1;
        int col = 0;
        while(row >= 0 && col < cols){
            if(array[row][col] == target)
                return true;
            if(array[row][col] < target)
                col++;
            else
                row--;
        }
        return false;
    }
};
