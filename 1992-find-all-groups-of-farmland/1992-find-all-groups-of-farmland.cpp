class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        
        vector<vector<int>>res;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==0)
                    continue;
                
                int r=i,c=j;
                while(c<n && v[i][c]==1)
                {
                    c++;
                }
                while(r<m &&v[r][j]==1)
                    r++;
               c = c==0 ? c: c-1;
                r = r==0 ? r : r-1;
                
                res.push_back({i,j,r,c});
                
        //       for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<v[i][j]<<" ";
        //     }
        //           cout<<endl;
        //       }
        //         cout<<endl;
                
                for(int x=i;x<r+1;x++)
                {
                    for(int y=j;y<c+1;y++)
                        v[x][y]=0;
                }
            }
        }
        return res;
    }
};