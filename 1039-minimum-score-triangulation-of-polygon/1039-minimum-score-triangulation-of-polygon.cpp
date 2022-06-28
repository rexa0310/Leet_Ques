class Solution {
public:
     int solve(vector<int>&v,int i,int j,vector<vector<int>>&dp){
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            int left = (dp[i][k]!=-1)? dp[i][k] : solve(v,i,k,dp);
            int right = (dp[k+1][j]!=-1)? dp[k+1][j] : solve(v,k+1,j,dp);
            int temp = left + right + v[i-1]*v[k]*v[j];
            ans = min(ans,temp);
        }
      return dp[i][j] = ans;  
    }
    int minScoreTriangulation(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(v,1,n-1,dp);
        
    }
};