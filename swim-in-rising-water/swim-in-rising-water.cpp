class Solution {
private:
    bool dfs(vector<vector<int>>& g,vector<vector<int>>&vis,vector<int>dx,vector<int>dy,int x,int r,int c,int n)
    {
        vis[r][c]=1;
        for (int i = 0; i < 4; ++i) 
        {
            int nr=r+dx[i], nc=c+dy[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && vis[nr][nc] == 0 && g[nr][nc] <= x)
            {
                if (nr == n-1 && nc == n-1) 
                    return true;
                if (dfs(g,vis,dx,dy,x,nr,nc,n))
                    return true;
            }
        }
        return false;
    }
    bool check(vector<vector<int>>& g,int x)
    {
         int n = g.size();
        vector<vector<int>>vis(n, vector<int>(n, 0));
        vector<int>dx({0,0,1,-1});
        vector<int>dy({1,-1,0,0});
        return dfs(g,vis,dx,dy,x,0,0,n);
    }
    public:
    int swimInWater(vector<vector<int>>& g)
    {
      int l=g[0][0],h=g.size()*g.size()-1;
        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(check(g,mid))
                h=mid;
            else
            l=mid+1;
        }
        return l;
    }
};