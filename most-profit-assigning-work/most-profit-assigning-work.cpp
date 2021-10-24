class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) 
    {
        vector<pair<int,int>>v;
        for(int i=0;i<d.size();i++)
            v.push_back(make_pair(d[i],p[i]));
        
        sort(v.begin(),v.end());
        sort(w.begin(),w.end());
        
        int i=0,s=0,m=0;
        for(auto x:w)
        {
           
            while(i<v.size() && x>=v[i].first)
            {
                m=max(m,v[i].second);
                 i++;
            }
           
            s+=m;
        }
        return s;
    }
};