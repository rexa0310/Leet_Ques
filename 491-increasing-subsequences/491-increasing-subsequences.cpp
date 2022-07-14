class Solution {
public:
     vector<vector<int>> findSubsequences(vector<int>& v) 
     {
        vector<vector<int>> res;
        vector<int> t;
        dfs(res, t, v, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& t, vector<int>& v, int pos) 
    {
        if(t.size() > 1)
            res.push_back(t);
        unordered_set<int> m;
        for(int i = pos; i < v.size(); ++i) 
        {
            if((t.empty() || v[i] >= t.back()) && m.find(v[i]) == m.end()) 
            {
                t.push_back(v[i]);
                dfs(res, t, v, i + 1);
                t.pop_back();
                m.insert(v[i]);
            }
        }
    }
};