class Solution {
public:
    int countNegatives(vector<vector<int>>& v)
    {
       int m=v.size();
        int n=v[0].size();
        int c=0;
        for(int i=0;i<m;i++)
        {
            int l=0,h=n-1;
            while(l<=h)
            {
                int mid=l+(h-l)/2;
                if(v[i][mid]>=0)
                    l=mid+1;
                else
                    h=mid-1;
            }
            c+=(n-h-1);
          //  cout<<c;
        }
        return c;
    }
};