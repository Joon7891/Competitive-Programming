class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        long int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = !obstacleGrid[0][0];
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (obstacleGrid[i][j]) continue;
                if (i + 1 < m && !obstacleGrid[i + 1][j]) dp[i + 1][j] += dp[i][j];
                if (j + 1 < n && !obstacleGrid[i][j + 1]) dp[i][j + 1] += dp[i][j];
            }
        }

        return (int) dp[m - 1][n - 1];
    }
};