class Solution {
public:
    int maxDistance(vector<int>& v1, vector<int>& v2)
    {
      reverse(v2.begin(),v2.end());
        int ans=0;
        int n=v1.size();
        for(int i=0;i<n;i++)
        {
            int idx=lower_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
            int j = v2.size() - 1 - idx;
            if(i<=j) 
                ans = max(ans,j-i);
        }
        return ans;
    }
};