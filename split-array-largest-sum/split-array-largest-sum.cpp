class Solution {
public:
    
    
    bool check(vector<int>&v,int x,int m)
    {
        int s=0;
        for(int i=0;i<v.size();i++)
        {
    ;
          if(s+v[i]<=x)
                 s+=v[i];
          else
            {
                m--;
                s=v[i];
                if(m<0)
                    return false;
            }
            
        }
        return true;
    }
    
    int splitArray(vector<int>& v, int m)
    {
        int l=0,r=0;
        m--;
        for(int i=0;i<v.size();i++)
        {
            r+=v[i];
            l=max(l,v[i]);
        }
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(check(v,mid,m))
                r=mid;
            else 
                l=mid+1;
        }
        return l;
    }
};