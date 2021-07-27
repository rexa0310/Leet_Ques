class Solution {
public:
    
    void solve(vector<int>& v,int i,vector<vector<int>>& res)
    {
     if(i==v.size()-1)
     {
         res.push_back({});
         res.push_back({v[i]});
     }
        else
        {
            solve(v,i+1,res);
            int n=res.size();
            for(int j=0;j<n;j++)
            {
                vector<int>x=res[j];
                x.push_back(v[i]);
                res.push_back(x);
            }
        }
    }
    vector<vector<int>> subsets(vector<int>&  v) {
       if (v.size()==0)
           return {{}};
        vector<vector<int>>res;
        solve(v,0,res);
        return res;
    }
};