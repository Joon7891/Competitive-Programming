class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();
        
        int dp[N + 2][N + 2];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < N; i++){
            dp[i][i] = (i + N) % 2 == 0 ? -piles[i] : piles[i];
        }
        
        for (int s = 2; s <= N; s++){
            for (int i = 0, j = s - 1; j < N; i++, j++){
                bool alex = (j + i + N) % 2;
                
                if (alex) dp[i][j] = max(dp[i + 1][j] + piles[i], dp[i][j - 1] + piles[j]);
                else dp[i][j] = min(dp[i + 1][j] - piles[i], dp[i][j - 1] + piles[j]);
            }
        }
        
        return dp[0][N - 1] > 0;
    }
};