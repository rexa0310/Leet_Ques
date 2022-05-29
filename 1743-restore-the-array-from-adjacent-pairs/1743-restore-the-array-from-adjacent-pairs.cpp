class Solution {
public:
    unordered_set<int> vis;
    map<int, vector<int>> adj;
    
    void dfs(int node, vector<int> &ans)
    {
        vis.insert(node);
        ans.push_back(node);
        
        for(auto &it: adj[node])
        {
            if(!vis.count(it))
            {
                dfs(it, ans);
            }
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& v)
    {
        int n = v.size();
        vector<int> ans;
      
        for(auto x: v)
        {
            int u = x[0], v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int src;
        
        for(auto [a, b]:adj)
        {
            if(b.size() == 1) 
            {
                src = a;
                break;
            }
        }
        
        dfs(src, ans);
        
        return ans;
    }
};