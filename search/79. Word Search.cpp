//深度优先搜索

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    bool exist(vector<vector<char> > &board, string word) {
        int height = board.size();
        if(height == 0)
            return false;
        int width = board[0].size();
        vector<vector<bool>> mask(height, vector<bool>(width, false));
        bool res = false;
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(DFS(board, word, i, j, mask, 0)){
                    res = true;
                    return res;
                }
            }
        }
        return res;
    }
    
    bool DFS(vector<vector<char>> &board, string &word, int x, int y,
            vector<vector<bool>> &mask, int pos){
        if(board[x][y] != word[pos])
            return false;
        mask[x][y] = true;
        if(pos == word.size() - 1)
            return true;
        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX >= 0 && newX < board.size() &&
              newY >= 0 && newY < board[0].size() && !mask[newX][newY]){
                if(DFS(board, word, newX, newY, mask, pos+1))
                    return true;
            }
        }
        mask[x][y] = false;
        return false;
    }
};
