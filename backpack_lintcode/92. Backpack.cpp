// 二维背包

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        sort(A.begin(), A.end());
        vector<vector<int>> dp(A.size(), vector<int>(m+1, 0));
        for(int j = 1; j <= m; j++){
            if(j >= A[0])
                dp[0][j] = A[0];
            for(int i = 1; i < A.size(); i++){
                if(j < A[i])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j-A[i]] + A[i], dp[i-1][j]);
            }
        }
        return dp[A.size()-1][m];
    }
};

//一维背包
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        sort(A.begin(), A.end());
        vector<int> dp(m+1, 0);
        for(int i = 0; i < A.size(); i++){
            for(int j = m; j >= 1; j--){
                 if(j >= A[i]){
                     dp[j] = max(dp[j-A[i]] + A[i], dp[j]);
                 }
            }
        }
        return dp[m];
    }
};


