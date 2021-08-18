class Solution {
public:
    int longestMountain(vector<int>& v) {
        
        if(v.size()<=2)
            return 0;
        int n=v.size();
        vector<int>l(n,1);
        vector<int>r(n,1);
        for(int i=1;i<n;i++)
          if(v[i]>v[i-1])
              l[i]=l[i-1]+1;
         for(int i=n-2;i>=0;i--)
          if(v[i]>v[i+1])
              r[i]=r[i+1]+1;
          
        int c=0;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<l[i]<<" ";
        // }
        // cout<<endl;
        //   for(int i=0;i<n;i++)
        // {
        //     cout<<r[i]<<" ";
        // }
         for(int i=0;i<n;i++)
             if(l[i]+r[i]>3 && l[i]>1 && r[i]>1)
                 c=max(c,l[i]+r[i]-1);
        return c;
    }
};