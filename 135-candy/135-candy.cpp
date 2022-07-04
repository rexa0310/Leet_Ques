class Solution {
public:
    int candy(vector<int>& v) {
         int n=v.size();
        vector<int>x(n,1);
        for(int i=1;i<n;i++)
        {
            if(v[i]>v[i-1] && x[i]<=x[i-1])
             x[i]=x[i-1]+1;
            
        }
        for(int i=n-2;i>=0;i--)
        {
          if(v[i]>v[i+1] && x[i]<=x[i+1]) 
              x[i]=x[i+1]+1;
          
        }
        return accumulate(x.begin(),x.end(),0);
    }
};