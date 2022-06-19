class Solution {
private:
     map<int, vector<int> > adj;
    vector<vector<int> > ans;
    
    void dfs(int node)
    {
        while(adj[node].size())
        {
            int next = adj[node].back();
            adj[node].pop_back();
            dfs(next);
            ans.push_back({node, next});
            
        }
        return;
    }
    public:

    vector<vector<int>> validArrangement(vector<vector<int>>& v) {
        map<int, int> ind;
        for(auto &p : v)
        {
            adj[p[0]].push_back(p[1]);
            ++ind[p[0]];
            --ind[p[1]];
        }
        int st = -1;
        for(auto &it: ind) 
            if(it.second >0)
                st = it.first;
        
        if(st == -1) 
            st = v[0][0];
        
        dfs(st);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};