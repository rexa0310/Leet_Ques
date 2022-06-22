class Solution {
public:
   int n;
    int dp[15][1<<14 + 1];
    int recur(int x,int mask,vector<int>&v){
        if(x==n/2)
            return 0;
        if(dp[x][mask]!=-1)
            return dp[x][mask];
            
        int ma=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((mask&(1<<(i)))==0 && (mask&(1<<j))==0)
                {
                    int nmask=(mask)|(1<<i);
                    nmask=nmask|(1<<j);
                    ma=max(ma,(x+1)*__gcd(v[j],v[i])+recur(x+1,nmask,v));
                }
            }
        }
        return dp[x][mask]=ma;
    }
    int maxScore(vector<int>& v) 
    {
        memset(dp,-1,sizeof(dp));
        n=v.size();
        return recur(0,0,v);
        
    }
};