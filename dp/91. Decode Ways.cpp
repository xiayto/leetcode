class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0')
            return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        if(n == 1)
            return dp[0];
        int t1 = stoi(s.substr(0, 2));
        if(s[1] != '0'){
            dp[1] = dp[0];
            if(t1 <= 26)
                dp[1]++;
        }else{
            if(t1 <= 26)
                dp[1] = 1;
        }
        for(int i = 2; i < n; i++){
            if(s[i] != '0')
                dp[i] += dp[i-1];
            int temp = stoi(s.substr(i-1, 2));
            if(temp >= 10 && temp <=26)
                dp[i] += dp[i-2];
        }
        return dp[n-1];
    }
};
