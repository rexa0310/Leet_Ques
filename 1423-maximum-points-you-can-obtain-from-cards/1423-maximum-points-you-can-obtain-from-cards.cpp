class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n=v.size(),s=0,n1=n-k;
        
        int sum=0;
        for(auto x:v)
            sum+=x;
    
        for(int i=0; i<n1; i++)
            s+=v[i];
        
        int ans=sum-s;
        for(int i=1; i<=k; i++)
        {
            s-=v[i-1];
            s+=v[i+n1-1];
            ans=max(ans,sum-s);
        }
        return ans;
    }
};