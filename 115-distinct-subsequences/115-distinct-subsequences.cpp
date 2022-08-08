class Solution {
public:
   int dp[1002][1002];
    
    int solve(string &s, string &t, int n, int m)
    {
        if(m<0)
            return 1;
        
        if(n<0)
            return 0;
        
      if(dp[n][m]!=-1)
        return dp[n][m];
        
        int c= solve(s,t,n-1,m);
        if(s[n]==t[m])
        {
            int take=solve(s,t,n-1,m-1);
            c+=take;
        }
     return dp[n][m]=c;
    }
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
       memset(dp,-1,sizeof(dp));
        return solve(s,t,n,m);
    }
};