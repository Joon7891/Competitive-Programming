class Solution {
public:
    int numTrees(int n) {
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 1; i <= n; i++) dp[i][i] = 1;
        
        for (int s = 2; s <= n; s++){
            for (int i = 1, j = s; j <= n; i++, j++){
                dp[i][j] += dp[i + 1][j];
                dp[i][j] += dp[i][j - 1];
                
                for (int k = i + 1; k <= j - 1; k++){
                    dp[i][j] += dp[i][k - 1] * dp[k + 1][j];
                }
            }
        }
        
        return dp[1][n];
    }
};