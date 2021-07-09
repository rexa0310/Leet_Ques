class Solution {
public:
    int minimumSize(vector<int>& v, int op) {
        int n=v.size();
        // if (op==1)
        // {
        //     int ma=0;
        //     for(int i=0;i<n;i++)
        //         ma=max(ma,v[i]);
        //     return ma;
        // }
        if(n==1 && v[0]==1 )
            return 1;
        long long h=0;
        for(int i=0;i<n;i++)
            h+=v[i];
       long long l=0;
         while(l<h)
         {
             long long mid=l+(h-l)/2;
             int c=0;
             for(int i=0;i<n;i++)
             {
                 if(v[i]>mid)
                 {
                     if(mid==0)
                         c++;
                 else
                     c+=(v[i]+mid-1)/mid-1;
                 }
             }
             if(c>op)
                 l=mid+1;
             else
                 h=mid;
         }
        return l;
    }
};