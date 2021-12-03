class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int n= nums.size();
        if(n==0)
            return 0;
        int m=-10000000 ,p=1;
        for(int i=0; i<n; i++)
        {
            p *= nums[i];
            m=max(m,p);
            if(nums[i]==0) 
                p=1;
        }
		
        p=1;
        for(int i=n-1; i>=0; i--)
        {
            p*= nums[i];
           m=max(m,p);
            if(nums[i]==0) 
                p=1;
        }
        return m;
    }
};