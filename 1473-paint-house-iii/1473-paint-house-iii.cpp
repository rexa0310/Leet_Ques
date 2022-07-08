class Solution {
public:
    int solve(int idx,int pre,int cur,vector<int>&house,vector<vector<int>>&c,int m,int n,int k,vector<vector<vector<int>>>&dp)
    {
        if(idx==m&&cur==k)
            return 0;
        if(idx>=m||cur>k)
            return 1e9;
        if(dp[idx][pre][cur]!=-1)
            return dp[idx][pre][cur];
        
        int ans=1e9;
        
        if(house[idx])
        {
            if(pre!=house[idx])
                ans=solve(idx+1,house[idx],cur+1,house,c,m,n,k,dp);
            
            else
                ans=solve(idx+1,house[idx],cur,house,c,m,n,k,dp);
        }
        
        else
        {
            int s=1e9;
            for(int i=0;i<n;i++)
            {
                if(i+1==pre)
                    s=solve(idx+1,i+1,cur,house,c,m,n,k,dp)+c[idx][i];
                else
                    s=solve(idx+1,i+1,cur+1,house,c,m,n,k,dp)+c[idx][i];
                ans=min(ans,s);
            }
        }
        return dp[idx][pre][cur]=ans;
    }
    
    int minCost(vector<int>& v, vector<vector<int>>& c, int m, int n, int k) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        
        
        int ans= solve(0,0,0,v,c,m,n,k,dp);
        return ans==1e9?-1:ans;
    
        
    }
};