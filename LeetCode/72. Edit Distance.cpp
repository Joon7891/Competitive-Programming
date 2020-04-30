class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.length();
        int M = word2.length();
        
        int dp[N + 1][M + 1];
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        for (int i = 0; i <= N; i++){
            dp[i][0] = i;
        }
        
        for (int i = 0; i <= M; i++){
            dp[0][i] = i;
        }
        
        
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= M; j++){
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        
        return dp[N][M];
    }
};