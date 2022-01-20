class Solution {
public:
    bool check(vector<vector<int>>& grid,int i,int j)
    {
       if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
       {
            return false;
        }
        return true;

    }
    bool dfs(vector<vector<int>>& grid,int i, int j)
    {
        if(check(grid,i,j)==false)
            return false;
        else
        {
            if(grid[i][j]==1)
                return true;
        grid[i][j]=1;
        bool d1 = dfs(grid, i+1, j);
        bool d2 = dfs(grid, i, j+1);
        bool d3 = dfs(grid, i-1, j);
        bool d4 = dfs(grid, i, j-1);
        return d1 && d2 && d3 && d4;
        }
        
    }
    int closedIsland(vector<vector<int>>& grid) {
       int res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!grid[i][j])
                {
                    if(dfs(grid,i,j))
                        res++;
                }
            }
        }
        return res;
    }
};