class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const int MAXN = 55;
        const int MAXM = 105;
        const int MAXK = 55;
        const int MOD = 1000000007;
        
        int dp[55][105][55];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 1; i <= m; i++){
            dp[1][i][1] = 1;
        }
        
        
        for (int a = 2; a <= n; a++){
            for (int b = 1; b <= m; b++){
                for (int c = 1; c <= k; c++){
                    for (int i = 0; i < b; i++) dp[a][b][c] = (dp[a][b][c] + dp[a - 1][b][c]) % MOD;
                    
                    for (int bPrev = 1; bPrev < b; bPrev++){
                        dp[a][b][c] = (dp[a][b][c] + dp[a - 1][bPrev][c - 1]) % MOD;
                    }
                }
            }
        }

        int total = 0;
        for (int i = 1; i <= m; i++){
            total = (total + dp[n][i][k]) % MOD;
        }
        
        return total;
    }
};