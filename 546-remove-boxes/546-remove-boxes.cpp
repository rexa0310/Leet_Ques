class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
     int dp[100][100][100]={0};
        
        int n = boxes.size();
        return operate(boxes, 0, n-1, 0,dp);   
    }

    int operate(vector<int>& boxes, int i, int j, int k,int dp[100][100][100])
    {
     
        if (i>j) 
            return 0;
       if(dp[i][j][k]>0)
           return dp[i][j][k];
           
        int res = (k+1)*(k+1) + operate(boxes, i+1, j, 0,dp);
        for (int m=i+1; m<=j; m++)
        {    
            if (boxes[i]==boxes[m])
        res = max( res, operate(boxes, i+1, m-1, 0,dp)+operate(boxes, m, j, k+1,dp));
        }
          dp[i][j][k]=res;
        return res;
    }
};