class Solution {
public:
    int findMaxForm(vector<string>& s, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(auto x:s)
        {
            int c0=0,c1=0;
            for(auto y:x)
            { 
                if(y=='0')
                    c0++;
               else
                c1++;
            }
             for (int i = m; i >= c0; i--) 
	              for (int j = n; j >= c1; j--) 
                    dp[i][j] = max(dp[i][j], dp[i - c0][j - c1] + 1);
	    }
  return dp[m][n];
    }
};