class Solution {
public:
    int check(int x,vector<int>v,int n)
    {
        int l=0,h=n;
        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(v[mid]<=x)
                l=mid+1;
            else
                h=mid;
        }
         if(l < n && v[l] <= x) 
           l++;
    
        return l;
    }
    int minSubArrayLen(int target, vector<int>& v) {
       int n=v.size();
        vector<int>pref(n);
        pref[0]=v[0];
        for(int i=1;i<n;i++)
            pref[i]=pref[i-1]+v[i];
        
        int i=n-1,res=INT_MAX;
        while(i>=0 && pref[i]>=target)
        {
           int j=check(pref[i]-target ,pref,n);
            cout<<j<<endl;
            res=min(res,i-j+1);
            
            i--;
        }
        if(res ==INT_MAX)
            return 0;
        return res;
    }
};