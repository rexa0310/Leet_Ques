class Solution {
public:
     int dp[100][100]={0};
    int strangePrinter(string s) {
     
        
        int n = s.size();
        return operate(s, 0, n-1);   
    }

    int operate(string s, int i, int j)
    {
     
        if (i>j) 
            return 0;
       if(dp[i][j]>0)
           return dp[i][j];
           
        int res =1+operate(s, i+1, j);
        for (int m=i+1; m<=j; m++)
        {    
            if (s[i]==s[m])
        res = min( res, operate(s, i+1, m-1)+operate(s, m, j));
        }
          dp[i][j]=res;
        return res;
    }
};