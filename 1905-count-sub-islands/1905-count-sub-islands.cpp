class Solution {
public:
      void dfs(vector<vector<int>>& grid, vector<vector<int>>& grid1,int i, int j,int& mila) 
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == 0)
        {
            return;
        }
          if(grid[i][j]==1)
          {
              if(grid1[i][j]==0)
              {
                  mila=0;
                  return;
              }
              grid[i][j]=0;
          }
              
        dfs(grid,grid1, i - 1, j,mila);
        dfs(grid,grid1, i + 1, j,mila);
        dfs(grid, grid1, i, j - 1,mila);
        dfs(grid, grid1,i, j + 1,mila);
      }
      
     
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid) {
         int res = 0;
        for (int i = 0; i < grid.size(); i++) 
        {
            for (int j = 0; j < grid[0].size(); j++) 
            {
                int mila=1;
                if (grid[i][j] == 1) 
                {
                     dfs(grid,grid1,i,j,mila);
                         
                         if(mila==1)
                         res++;
                }
            }
        }
    
        return res;
    }
};