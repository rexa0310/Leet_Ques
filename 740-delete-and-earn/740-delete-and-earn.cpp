class Solution {
public:
    int deleteAndEarn(vector<int>& v) {
     int n=10001;
        vector<int>dp(n,0),s(n,0);
        for(auto x:v)
        {
            s[x]+=x;
        }
        dp[1]=s[1];
        for(int i=2;i<n;i++)
            dp[i]=max(dp[i-2]+s[i],dp[i-1]);
        
        return dp[n-1];
    }
};