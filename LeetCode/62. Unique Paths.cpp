class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m + 2][n + 2];
        memset(dp, 0, sizeof(dp));
        
        dp[1][1] = 1;
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                dp[i + 1][j] += dp[i][j];
                dp[i][j + 1] += dp[i][j];
            }
        }
        
        return dp[m][n];
    }
};