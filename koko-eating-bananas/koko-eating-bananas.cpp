class Solution {
public:
    int minEatingSpeed(vector<int>& v, int m)
    {
        if(v.size()==1)
            return v[0]%m?v[0]/m+1:v[0]/m;
        
        int maxi=INT_MIN;
     for(auto x:v)
         maxi=max(maxi,x);
        long long l=1,h=maxi;
     
        while(l<h)
        {
            long long mid=l+(h-l)/2;
            long long c=0;
            for(auto x:v)
            {
                c+=x/mid;
                if(x%mid)
                    c++;
                
            }
            if(c>m)
                l=mid+1;
            else
                h=mid;
        }
        return h;
    }
};