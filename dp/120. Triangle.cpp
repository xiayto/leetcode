class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0)
            return 0;
        vector<vector<int>> dp;
        for(int i = 0; i < triangle.size(); i++){
            dp.push_back(vector<int>());
            for(int j = 0; j < triangle[i].size(); j++)
                dp[i].push_back(0);
        }
        for(int i = 0; i < triangle[n-1].size(); i++)
            dp[n-1][i] = triangle[n-1][i];
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < dp[i].size(); j++)
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
        }
        
        return dp[0][0];
    }
};
