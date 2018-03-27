// 卡特兰数，记得初始化数组

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);  //初始化数组
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};
