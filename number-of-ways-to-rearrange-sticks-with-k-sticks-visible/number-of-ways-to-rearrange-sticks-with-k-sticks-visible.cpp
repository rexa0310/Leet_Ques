class Solution {
public:
    int mod=1000000000+7;
   long fact[1001]={};
   long   dfs(int n ,int k , vector<vector<long>> &dp)
    {
        if(k==n)
        {
            return 1;
           
        }
        if(k==0 || n<k)
        {
           return  0;
    
        }
       if (k == 1) return fact[n - 1];
        if (dp[n][k]) return dp[n][k];
        long ans = 0;
        ans = (ans + dfs(n - 1, k,dp) * (n - 1) % mod) % mod;
        ans = (ans + dfs(n - 1, k - 1,dp)) % mod;
         dp[n][k] = ans;
        
        return dp[n][k];
    }
    
    int rearrangeSticks(int n, int k) {
        vector<vector<long>>dp(n+1,vector<long >(k+1,0));
         fact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        long   res=  dfs(n,k,dp);
        return res;
    }
};