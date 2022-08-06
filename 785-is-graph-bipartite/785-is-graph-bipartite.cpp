class Solution {
public:
    bool dfs(vector<vector<int>>& v,vector<int>& vis, int node,vector<int>& clr,int prev)
    {
     vis[node]=1;
        
        clr[node]=1-prev;
        for(auto x:v[node])
        { 
            if(!vis[x])
            {
                if(!dfs(v,vis,x,clr,clr[node]))
                    return false;
            }
            else
            {
                if(clr[x]==clr[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& v) {
        int n=v.size();
        vector<int>vis(n,0);
        vector<int>clr(n,-1);
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && !dfs(v,vis,i,clr,0))
                 return false;
        }
        return true;
        
    }
};