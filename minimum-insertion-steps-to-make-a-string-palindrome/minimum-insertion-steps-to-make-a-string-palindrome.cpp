class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &s,int i,int j)
    {
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==s[j])
           return  dp[i][j]=solve(s,i+1,j-1);
        else
           return  dp[i][j]=1 +min(solve(s,i+1,j),solve(s,i,j-1));
    }
    int minInsertions(string s)
    {
        dp.resize(s.length(),vector<int>(s.length(),-1));
        
    return solve(s,0,s.length()-1);
    }
};