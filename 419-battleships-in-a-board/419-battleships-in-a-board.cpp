class Solution {
public:
    int countBattleships(vector<vector<char>>& v)
    {
      if(v.size()==0 && v[0].size()==0)
          return 0;
        
        int n=v.size(),m=v[0].size(),c=0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='X' )
                {
                    if(i>0 && v[i-1][j]=='X' )
                        continue;
                    if(j>0 && v[i][j-1]=='X')
                        continue;
                    
                    c++;
                }
            }
        return c;
    }
};