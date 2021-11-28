class Solution {
public:
    
    vector<vector<int>>res;
    int target;
    
    void distinct_paths(int start,vector<int> & x,vector<vector<int>> &graph)
    {
        if(start == target)
        {
            res.push_back(x);
            return;
        }
        
        else
        {
            for(int u : graph[start])
            {
               x.push_back(u);
    
             distinct_paths(u,x,graph);
              
               x.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        target=graph.size()-1;
        vector<int>x;
        x.push_back(0);
        
        distinct_paths(0,x,graph);
        return res;
    }

};