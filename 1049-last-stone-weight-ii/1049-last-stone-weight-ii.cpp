class Solution {
public:
  int solve(vector<int>& v, int i, int d, vector<vector<int>>& dp) {
        int n = v.size();
        int x = abs(d);
        
        if(i == n)
            return x;
        if(dp[i][x] != -1)
            return dp[i][x];
        
        int l = solve(v, i+1, d + v[i], dp);
        int r = solve(v, i+1, d - v[i], dp);
        
        return dp[i][x] = min(l, r);
    }
    
    int lastStoneWeightII(vector<int>& v) 
    {
        int n = v.size();
        int s = accumulate(begin(v), end(v), 0);
        vector<vector<int>> dp(n, vector<int>(s + 1, -1));
        
        return solve(v, 0, 0, dp);
        
    }
};