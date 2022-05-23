class Solution {
public:
    int countSubstrings(string s) {
        if(s.length()<2)
            return s.length();
        int n=s.length();
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        
        for(int i=0;i<n;i++)
                    dp[i][i]=true;
        int c=s.length();
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i==1 || dp[i+1][j-1])
                    {
                        dp[i][j]=true;
                        c++;
                    }
                }    
            }
        }
            return c;
    }
};