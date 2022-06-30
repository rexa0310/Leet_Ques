class Solution {
public:
    int maxAbsoluteSum(vector<int>& v)
    {
        int n = v.size();
       vector<int>maxi(n+1,0),mini(n+1,0);
        
        int ans = INT_MIN;
        for(int i=1;i<n+1;i++)
        {
        maxi[i]=max(v[i-1],maxi[i-1]+v[i-1]);
        mini[i]=min(v[i-1],mini[i-1]+v[i-1]);
        ans = max({ans,maxi[i],abs(mini[i])});
        }
        
        return ans;
    }
};