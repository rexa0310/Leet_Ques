class Solution {
public:
    int matrixScore(vector<vector<int>>& v)
    {
      int n=v.size();
        int m=v[0].size();
        for(int i=0;i<n;i++)
        {
            if(v[i][0]==0)
            {
                for(int j=0;j<m;j++)
                    v[i][j]=1-v[i][j];
            }
        }
        
        for(int i=1;i<m;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
                c+=v[j][i];
            if(c<(n+1)/2)
            {
              for(int j = 0; j <n; ++j) 
              {
                    v[j][i] ^= 1;  
              }
            }
       
        }
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             cout<<v[i][j];
    //         }
    //     cout<<endl;
    // }
        int res=0,p=1;
        for(int j=m-1;j>=0;j--)
        {
            for(int i=0;i<n;i++)
                res=res+v[i][j]*p;
            p<<=1;
        }
        return res;
    }
};