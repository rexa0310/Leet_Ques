class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
         int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[0] = grid[0];

    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                int cost = dp[i-1][j] + grid[i][k] + moveCost[grid[i-1][j]][k];
                dp[i][k] = min(dp[i][k], cost);
            }
        }
    }

    return *min_element(dp.back().begin(), dp.back().end());
    }
};