class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& v, int k)
    {
      multimap<int,int>m;
        for(int i=0;i<v.size();i++)
         m.insert({v[i][0]*v[i][0]+v[i][1]*v[i][1],i});
        
        vector<vector<int>>res;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(k>0)
            {
                res.push_back(v[it->second]);
                k--;
            }
            else
                break;
        }
        return res;
    }
};