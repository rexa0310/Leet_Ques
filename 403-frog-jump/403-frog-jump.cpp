class Solution {
public:
    int dp[2001][2001];
    
    bool solve(vector<int>&v, int idx,int k)
    {
        if(idx>=v.size())
            return false;
        if(idx==v.size()-1)
            return true;
        
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        
        int res=0;
        for(int i=-1;i<=1;i++)
        {
            int cur=i+k;
            if(cur>0)
            {
            int it=lower_bound(v.begin(),v.end(),v[idx]+cur)-v.begin();
              if(it== v.size() || v[it]!=v[idx]+cur) 
                  continue;
              res=res||solve(v,it,cur);
            }
        }
        return dp[idx][k]=res;
        
    }
    bool canCross(vector<int>& v) {
     memset(dp,-1,sizeof(dp));
        return solve(v,0,0);
    }
};