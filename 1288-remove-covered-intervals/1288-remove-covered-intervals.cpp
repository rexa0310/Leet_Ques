class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) 
    {
       sort(v.begin(),v.end());
        int l=-1,r=-1,c=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i][0] > l && v[i][1]>r)
            {
                  l=v[i][0];
                c++;
            }
          
            r=max(r,v[i][1]);     
        }
        return c;
    }
};