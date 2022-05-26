class Solution {
public:
    int earliestFullBloom(vector<int>& u, vector<int>& v)
    {
      vector<pair<int,int>>p;
        for(int i=0;i<v.size();i++)
            p.push_back({v[i],u[i]});
        sort(p.begin(),p.end(),greater<pair<int,int>>());
            
            int m=-1,pt=0;
        for(auto i:p)
        {
            int y=i.second;
            int x=i.first;
            
            pt+=y;
           int gt=pt+x+1;
            m=max(m,gt);
        }
        return m-1;
    }
};