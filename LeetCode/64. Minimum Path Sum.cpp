class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        
        int dp[M][N];
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        
        dp[0][0] = grid[0][0];
        for (int i = 1; i < N; i++){
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        
        for (int i = 1; i < M; i++){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        
        for (int i = 1; i < M; i++){
            for (int j = 1; j < N; j++){                
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }

        return dp[M - 1][N - 1];
    }
};