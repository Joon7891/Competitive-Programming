class Solution {
public:    
    int n, m;
    vector<pair<int, int>> dir {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    
    bool in_grid(int x, int y){
        return 0 <= x && x < n && 0 <= y && y < m;
    }
    
    int dfs(int x, int y, vector<vector<int>>& a, vector<vector<int>>& dp){
        if (dp[x][y] != 0) return dp[x][y];
        
        int best = 1;
        for (pair<int, int> d : dir){
            int xNew = d.first + x;
            int yNew = d.second + y;            
            if (in_grid(xNew, yNew) && a[xNew][yNew] > a[x][y]){
                best = max(best, 1 + dfs(xNew, yNew, a, dp));
            }
        }
        
        return dp[x][y] = best;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if ((n = matrix.size()) == 0) return 0;
        if ((m = matrix[0].size()) == 0) return 0;
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        int best = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                best = max(best, dfs(i, j, matrix, dp));
            }
        }

        return best;
    }
};