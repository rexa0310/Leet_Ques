class Solution {
public:
  
    int countSubstrings(string s, string t) {
        
        
     int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        vector<vector<int>> dp1(n+1,vector<int>(m+1));
        int ans = 0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                    dp1[i][j] = dp1[i-1][j-1];
                }
                else
                    dp1[i][j] = 1+dp[i-1][j-1];
                ans += dp1[i][j];
            }
        }
        return ans;
    }
};