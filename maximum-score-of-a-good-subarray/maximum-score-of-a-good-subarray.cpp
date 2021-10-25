class Solution {
public:
    int maximumScore(vector<int>& nums, int k) 
    {
          int n=nums.size();
        if(n==1)
            return nums[0];
        int i=k,j=k;
        int mn=nums[k];
        int ans=0;
        while(i>0 || j<n-1)
        {
            if(i==0)
                j++;
            else if(j==n-1)
                i--;
            else if(nums[i-1] < nums[j+1])
               j++;
            else
               i--;
            
            mn=min(mn, min(nums[i],nums[j]));
             ans=max(ans,mn*(j-i+1));
        }
        return ans;
    }
};