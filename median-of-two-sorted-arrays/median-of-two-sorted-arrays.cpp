class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) 
    {
      if(v1.size()>v2.size())
          return  findMedianSortedArrays(v2, v1);
          int m=v1.size(),n=v2.size();
           int l=0,r=m;
        while(l<=r)
        {
            int c1=l+(r-l)/2;
            int c2=(m+n+1)/2-c1;
            
            int l1=INT_MIN;
            if(c1!=0)
                l1=v1[c1-1];
            int l2=INT_MIN;
            if(c2!=0)
                l2=v2[c2-1];
            int r1=INT_MAX;
            if(c1!=m)
                r1=v1[c1];
            int r2=INT_MAX;
            if(c2!=n)
                r2=v2[c2];
            
            if(l1<=r2 && l2<=r1)
            {
                if((n+m)%2==0)
                return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return max(l1,l2);
            }
            else if(l1>r2)
                r=c1-1;
            else
                l=c1+1;
                
        }
        return 0.0;
    }
};