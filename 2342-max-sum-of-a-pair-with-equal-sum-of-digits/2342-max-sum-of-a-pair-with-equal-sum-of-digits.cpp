class Solution {
public:
    int maximumSum(vector<int>& v) {
      unordered_map<int,int>mp;
        int n = v.size();
        int ans = -1;
        for(int j=0; j<n; j++)
        {
            int x = v[j] , sum = 0;
            while(x>0)
            {
                int rem = x%10;
                sum += rem;
                x/=10;
            }
            
            if(mp.count(sum))
                ans = max(ans,mp[sum]+v[j]);
            
            mp[sum] = max(mp[sum] , v[j]);
        }
        
        return ans;   
    }
};