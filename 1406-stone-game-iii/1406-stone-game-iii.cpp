class Solution {
public:
    
    int dp[50001];
    int solve(vector<int>& v, int idx)
    {
        if(idx>=v.size())
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        int ans=INT_MIN;
        
        ans=max(ans,v[idx]-solve(v,idx+1));
        if(idx+1<v.size())
            ans=max(ans,v[idx]+v[idx+1]-solve(v,idx+2));
        if(idx+2<v.size())
            ans=max(ans,v[idx]+v[idx+1]+v[idx+2]-solve(v,idx+3));
        
        return dp[idx]=ans;
        
    }
    string stoneGameIII(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        int diff= solve(v,0);
        cout<<diff;
        if(diff>0)
            return "Alice";
        else if(diff==0)
            return"Tie";
        return "Bob";
    }
};