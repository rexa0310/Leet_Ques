class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {
      
        int n=v.size();
        int m=v[0].size();
        if (v[0][0] || v[n-1][m-1])
            return -1;
     
      if(n==1 && m==1)
          return 1;
       queue<pair<int,int>>q;   
        q.push({0, 0});
     int res=1;
        v[0][0] = -1;
        while (!q.empty())
        {
            int l=q.size();
            for(int i=0;i<l;i++)
            {   
                auto [cx, cy] = q.front();
                q.pop();
                int mx=min(cx+1,n-1);
                int my=min(cy+1,m-1);
                for (int x = max(0, cx - 1); x<= mx; x++)
                {
                //    cout<<mx<<" "<<my<<endl;
                    for (int y = max(0, cy - 1);y<=my; y++)
                    {
                        
                        if (x ==n-1 && y == m-1)
                        {
                            res++;
                            return res;
                        }
                        
                        if (v[x][y]==0)
                        {
                            v[x][y] = -1;
                            q.push({x, y});
                        }
                    }
                }
            }
        
            res++;
        }
        return -1; 
    }
};