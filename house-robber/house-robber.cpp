class Solution {
public:
    int rob(vector<int>& v) {
        int n=v.size();
        if(n==0)
            return 0;
        if(n==1)
            return v[0];
        if(n==2)
            return max(v[1],v[0]);
        vector<int>dp(n,0);
        dp[0]=v[0],dp[1]=v[1],dp[2]=v[2]+v[0];
        for(int i=3;i<n;i++)
            dp[i]=max(dp[i-2],dp[i-3])+v[i];
        return max(dp[n-2],dp[n-1]);
    }
};