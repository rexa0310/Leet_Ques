class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& g) 
    {
        int m = 0;
        
        for (int i = 0; i < g.size(); i++)
        {
            for (int j = 0; j < g[0].size(); j++)
            {
                int s = Area(i, j, g);
                m = max(m,s);
            }
        }
        
        return m;
    }
    
    int Area(int i, int j, vector<vector<int>>& g) 
    {
        if (i < 0 or i >= g.size()) return 0;
        if (j < 0 or j >= g[0].size()) return 0;
        if (g[i][j] == 0) return 0;
        
        int c = 1;
        g[i][j] = 0;
        
        c += Area(i, j+1, g);
        c += Area(i, j-1, g);
        c += Area(i+1, j, g);
        c += Area(i-1, j, g);
        
        return c;
    }
};