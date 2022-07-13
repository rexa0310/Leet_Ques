class Solution {
public:
    int maxDotProduct(vector<int>& v1, vector<int>& v2) {
         int n=v1.size(),m=v2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
        
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j) 
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j - 1], 0) + v1[i - 1] * v2[j - 1]);
            }
        }
        return dp[n][m];
    }
};