class Solution {
public:
    string longestPalindrome(string s)
    {
        int l=s.length();
          if(l<2)
            return s;
        vector<vector<bool>>dp(l,vector<bool>(l,false));
        for(int i=0;i<l;i++)
            dp[i][i]=true;
        
        int res=1,ml=0;
        for(int i=l-1;i>=0;i--)
        {
            for(int j=i+1;j<l;j++)
            {
                if(s[i]==s[j])
                {
                    if((j-i)==1 || dp[i+1][j-1])
                    {
                        dp[i][j]=true;
                    if(res<j-i+1)
                    {
                       res=j-i+1;
                        ml=i;
                    }
                    }
                
                }
            }
        }
        return s.substr(ml,res) ;
    }
};