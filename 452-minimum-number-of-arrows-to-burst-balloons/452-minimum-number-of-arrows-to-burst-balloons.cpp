class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v)
    {
      sort(v.begin(),v.end());
        int xs=v[0][0],xe=v[0][1];
        int c=1;
        for(int i=1;i<v.size();i++)
        {
          if(v[i][0]>=xs && v[i][0] <=xe)
          {
              xs=max(v[i][0],xs);
              xe=min(v[i][1],xe);
              
          }
            else
            {
                c++;
                xs=v[i][0];
                xe=v[i][1];
            }
            
        }
        return c;
    }
};