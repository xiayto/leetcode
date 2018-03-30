// 一维数组解

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        vector<int> dp(m+1, 0);
        for(int i = 0; i < A.size(); i ++){
            for(int j = m; j >= 1; j--){
                if(j >= A[i]){
                    dp[j] = max(dp[j-A[i]] + V[i], dp[j]);
                }
            }
        }
        return dp[m];
    }
};

//二维数组

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        vector<vector<int>> dp(A.size(), vector<int>(m+1, 0));
        for(int j = 1; j <= m; j++){
            if(j >= A[0])
                dp[0][j] = V[0];
            for(int i = 1; i < A.size(); i++){
                if(j < A[i])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j-A[i]]+V[i], dp[i-1][j]);
            }
        }
        return dp[A.size()-1][m];
    }
};
