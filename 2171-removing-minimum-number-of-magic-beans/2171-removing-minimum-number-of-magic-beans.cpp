class Solution {
public:
    long long minimumRemoval(vector<int>& v) {
        sort(v.begin(),v.end());
        vector<long long>s(v.size());
    
        s[0]=v[0];
        int n=v.size();
        for(int i=1;i<n;i++)
            s[i]=s[i-1]+v[i];
        
        long long ans=s[n-1]-(n*s[0]);
        
        for(int i=1;i<s.size();i++)
        {
            long long k=s[i-1]+s[n-1]-s[i]-(long long)(n-1-i)*(long long)v[i];
            ans=min(ans,k);
        }
        return ans;
    }
};