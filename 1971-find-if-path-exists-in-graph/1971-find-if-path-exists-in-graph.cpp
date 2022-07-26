class Solution {
public:
   bool dfs(vector<vector<int>>& g, vector<int>& vis, int x, int ds) {
      if(x==ds)
          return true;
       
       if(vis[x])
           return false;
       vis[x]=1;
       for(auto it:g[x])
           if(!vis[it] and dfs(g,vis,it,ds))
               return true;
       return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int ds) 
    {
        vector<vector<int>> g(n);
        for(int i=0; i<edges.size(); i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n, 0);
        return dfs(g, vis, start, ds);  
    }
};