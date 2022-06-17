class Solution {
public:
    int solve(int x,vector<int>&v, vector<int>&dp,int d,int n)
    {
        if(dp[x])
            return dp[x];
        int c=1;
        for(int j=x+1;j<=min(n-1,x+d);j++)
        {
            if(v[j]>=v[x])
                break;
            c=max(c,1+solve(j,v,dp,d,n));
        }
        for(int j=x-1;j>=max(0,x-d);j--)
        {
            if(v[j]>=v[x])
                break;
            c=max(c,1+solve(j,v,dp,d,n));
        }
        
        return dp[x]=c;
    }
    int maxJumps(vector<int>& v, int d) {
        vector<int>dp(1001,0);
        int n=v.size();
        int ans=1;
        for(int i=0;i<n;i++)
            ans=max(ans,solve(i,v,dp,d,n));
        
        return ans;
    }
};