class NumMatrix {
public:
    vector<vector<int>> dp;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
                
        dp.resize(n, vector<int>(m, 0));
        dp[0][0] = matrix[0][0];
        for (int j = 1; j < m; j++) {
            dp[0][j] = dp[0][j - 1] + matrix[0][j];
        }
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + matrix[i][0];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = dp[row2][col2];
        int b = row1 > 0 ? dp[row1 - 1][col2] : 0;
        int c = col1 > 0 ? dp[row2][col1 - 1] : 0;
        int d = (row1 > 0 && col1 > 0) ? dp[row1 - 1][col1 - 1] : 0;
        return a - b - c + d;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */