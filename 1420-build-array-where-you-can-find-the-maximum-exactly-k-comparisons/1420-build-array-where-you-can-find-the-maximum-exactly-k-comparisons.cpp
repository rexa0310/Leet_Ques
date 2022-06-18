class Solution {
public:
    int dp[51][101][51];
    
    int solve(int n,int m, int k,int cnt, int mx)
    {
           if (n == cnt)
           return k == 0;
          if (k < 0)
            return 0;
        
        if(dp[cnt][mx][k]==0)
        {
            dp[cnt][mx][k]=1;
            
            for(int x=1;x<=m;x++)
            {
                if(mx<x)
                   dp[cnt][mx][k] += solve(n, m, k -1, cnt + 1, max(mx,x));
                else
                   dp[cnt][mx][k] += solve(n, m, k, cnt + 1, max(mx,x));  
                
                dp[cnt][mx][k] %= 1000000007;
            }
        }
        return dp[cnt][mx][k]-1;
    }
    int numOfArrays(int n, int m, int k) {
        return solve(n,m,k,0,0);
    }
};