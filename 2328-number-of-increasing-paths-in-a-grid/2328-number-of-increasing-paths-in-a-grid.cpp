class Solution {
    
public:
     int MOD=1e9+7;
     vector<int> dir={0,1,0,-1,0};
    vector<vector<long>> dp;
    long solve(vector<vector<int>>& g,int i,int j) 
    {
        long res=1;  
        if(dp[i][j]!=-1) 
            return dp[i][j];
        for(int d=0;d<4;d++) 
        { 
            int x=i+dir[d],y=j+dir[d+1];
            if(x>=0&&y>=0&&x<g.size()&&y<g[0].size()&&g[x][y]>g[i][j])
                res=(res+solve(g,x,y))%MOD;       
        }
        return dp[i][j]=res;
    }
    
    int countPaths(vector<vector<int>>& g) {
        long res=0;
        dp.resize(g.size(),vector<long>(g[0].size(),-1));
        for(int i=0;i<g.size();i++)     
            for(int j=0;j<g[0].size();j++)
                res=(res+solve(g,i,j))%MOD;
        
        return res;
    }
};