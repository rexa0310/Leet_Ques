class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>& mat,int x,int i, int j)
    {
         if(i<0 || i>=n ||j<0 || j>=m)
            return 0;
        if(mat[i][j]<=x)
            return 0;
        if(dp[i][j])
            return dp[i][j];
        
        int d=dfs(mat,mat[i][j],i+1,j);
        int u=dfs(mat,mat[i][j],i-1,j);
        int l=dfs(mat,mat[i][j],i,j-1);
        int r=dfs(mat,mat[i][j],i,j+1);
        dp[i][j]=max({l,r,u,d})+1;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
          n=mat.size();
        m=mat[0].size();
        dp.resize(n,vector<int>(m));
        int m1=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                m1=max(m1,dfs(mat,INT_MIN,i,j));
        }
        return m1;
    }
};