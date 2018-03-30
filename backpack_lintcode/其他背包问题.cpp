// 重量+最大价值+物品可以重复选择

public int backPackIII(int m, vector<int> A, vector<int> V) {
    vector<int> dp(m+1, 0);
    for (int i = 0; i < A.length; i++) {
        for (int j = 1; j <= m; j++) {
            if (j >= A[i]) {
                dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
            }
        }
    }
    return dp[m];
}


// 
//https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4?tpId=37&tqId=21239&tPage=1&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
