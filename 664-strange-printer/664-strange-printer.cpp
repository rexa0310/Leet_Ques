class Solution {
public:
    int strangePrinter(string s) {
      int dp[100][100]={0};
        
        int n = s.size();
        return operate(s, 0, n-1,dp);   
    }

    int operate(string s, int i, int j,int dp[100][100])
    {
     
        if (i>j) 
            return 0;
       if(dp[i][j]>0)
           return dp[i][j];
           
        int res =1+operate(s, i+1, j,dp);
        for (int m=i+1; m<=j; m++)
        {    
            if (s[i]==s[m])
        res = min( res, operate(s, i+1, m-1,dp)+operate(s, m, j,dp));
        }
          dp[i][j]=res;
        return res;
    }
};