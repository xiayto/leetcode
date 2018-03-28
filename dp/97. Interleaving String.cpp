class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1 + n2 != s3.size())
            return false;
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n1; i++){
            if((dp[i-1][0] == 1) && (s3[i-1] == s1[i-1]))
                dp[i][0] = 1;
        }
        for(int j = 1; j <= n2; j++){
            if((dp[0][j-1] == 1) && (s3[j-1] == s2[j-1]))
                dp[0][j] = 1;
        }
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if((dp[i-1][j] == 1) && (s3[i+j-1] == s1[i-1]))
                    dp[i][j] = 1;
                if((dp[i][j-1] == 1) && (s3[i+j-1] == s2[j-1]))
                    dp[i][j] = 1;
            }
        }
        return dp[n1][n2];
    }
};
